/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
 *
 * If a copy of the EUPL was not distributed with this file, You can obtain
 * one at https://opensource.org/licenses/EUPL-1.2.
 *
 * The 'Compatible Licences' set out in the Appendix to the EUPL (as may be
 * amended by the European Commission) shall be deemed incompatible for
 * the purposes of the Work and the provisions of the compatibility
 * clause in Article 5 of the EUPL shall not apply.
 *
 * If using the Work as, or as part of, a network application, by
 * including the attribution notice(s) required under Article 5 of the EUPL
 * in the end user terms of the application under an appropriate heading,
 * such notice(s) shall fulfill the requirements of that article.
 * ********************************************************************* */

#include "ExampleHashTests.hpp"
#include "../../examples/C/Hash/OfflineProcessing.c"

class ExampleHashTestOfflineProcessing : public ExampleHashTest {
private:
	string getOutputFilePath() {
		stringstream output;
		uint32_t i = 0;
		while (evidenceFilePath[i] != '.' && evidenceFilePath[i] != '\0') {
			output << evidenceFilePath[i++];
		}
		output << ".processed.csv";
		return output.str();
	}

	class COutRedirector {
	private:
		std::streambuf* _sbuf;
	public:
		COutRedirector(const std::shared_ptr<std::stringstream>& _buffer) {
			_sbuf = std::cout.rdbuf();
			std::cout.rdbuf(_buffer->rdbuf());
		}
		~COutRedirector() {
			// Revert the capture.
			std::cout.rdbuf(_sbuf);
		}
	};
public:
	void run(fiftyoneDegreesConfigHash config) {
		// Capture stdout for the test.
		auto const ss = std::make_shared<std::stringstream>();
		{
			COutRedirector redirector(ss);
			fiftyoneDegreesOfflineProcessingRun(
				dataFilePath.c_str(),
				evidenceFilePath.c_str(),
				getOutputFilePath().c_str(),
				"IsMobile,BrowserName,DeviceType",
				config,
				stdout);
			fiftyoneDegreesFileDelete(getOutputFilePath().c_str());
		}
		std::string s = ss->str();
		const char* const fakeString = nullptr;
		ASSERT_NE(s.c_str(), fakeString);
	}
};

EXAMPLE_HASH_TESTS(ExampleHashTestOfflineProcessing)