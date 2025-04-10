param (
    [string]$RepoName
)

$WorkDir = [IO.Path]::Combine($pwd, $RepoName)
$PackagePath = [IO.Path]::Combine($pwd, "package")
$BuildPath = [IO.Path]::Combine($WorkDir, "build")
$BinPath = [IO.Path]::Combine($BuildPath, "bin")

mkdir $BuildPath

# Copy the prebuilt build dir with binaries and artifacts for tests into workdir
Copy-Item -Path $PackagePath/* -Destination $WorkDir -Recurse

Write-Output "PackagePath contents:"
ls $PackagePath

Write-Output "BuildPath contents:"
ls $BuildPath

Write-Output "BinPath contents:"
ls $BinPath
