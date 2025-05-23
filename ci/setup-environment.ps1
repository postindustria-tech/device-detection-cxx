param(
    [string]$ProjectDir = ".",
    [string]$Name = "Release_x64",
    [string]$Arch = "x64",
    [string]$Configuration = "Release",
    [string]$BuildMethod = "cmake"
)

if ($BuildMethod -eq "msbuild") {

    # Setup the MSBuild environment if it is required.
    ./environments/setup-msbuild.ps1

}

if ($IsLinux -or $IsMacOS) {
    pipx install 'gcovr~=7.2' || $(throw "gcovr install failed")
}
