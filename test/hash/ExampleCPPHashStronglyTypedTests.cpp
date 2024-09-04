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
#include "../../examples/CPP/Hash/StronglyTyped.cpp"


class ExampleCPPHashStronglyTypedTests : public ExampleHashTest {
public:
	void run(fiftyoneDegreesConfigHash configHash) {
		// Capture stdout for the test.
		testing::internal::CaptureStdout();

		DeviceDetection::Hash::ConfigHash* config = 
			new DeviceDetection::Hash::ConfigHash(&configHash);
		StronglyTyped* stronglyTyped =
			new StronglyTyped(dataFilePath, config);
		stronglyTyped->run();
		delete stronglyTyped;

		// Don't print output
		std::string output = testing::internal::GetCapturedStdout();
	}
};

EXAMPLE_HASH_TESTS(ExampleCPPHashStronglyTypedTests)