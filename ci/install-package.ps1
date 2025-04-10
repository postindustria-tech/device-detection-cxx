param (
    [string]$RepoName
)

$PackagePath = [IO.Path]::Combine($pwd, "package")
$BuildPath = [IO.Path]::Combine($pwd, $RepoName, "build")
$BinPath = [IO.Path]::Combine($BuildPath, "bin")

mkdir $BuildPath

# Copy the prebuilt binaries to the build directory
#Copy-Item -Recurse -Path $PackagePath -Destination $BinPath
Copy-Item -Path $PackagePath/* -Destination $BuildPath -Recurse

Write-Output "PackagePath contents:"
ls $PackagePath

Write-Output "BuildPath contents:"
ls $BuildPath

Write-Output "BinPath contents:"
ls $BinPath
