param (
    [string]$RepoName
)

$WorkDir = [IO.Path]::Combine($pwd, $RepoName)
$PackagePath = [IO.Path]::Combine($pwd, "package")

# Copy the prebuilt build dir with binaries and artifacts for tests into workdir
Copy-Item -Path $PackagePath/* -Destination $WorkDir -Recurse

Write-Output "PackagePath contents:"
ls $PackagePath

Write-Output "WorkDir contents:"
ls $WorkDir
