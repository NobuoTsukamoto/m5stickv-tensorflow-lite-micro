# M5StickV TensorFlow lite for micro examples.
This repository builds the sample of TensorFlow Lite for micro for M5StickV.

- [Standalone SDK for kendryte K210](https://github.com/kendryte/kendryte-standalone-sdk)
- [TensorFlow](https://github.com/tensorflow/tensorflow)
- [TensorFlow Lite for Microcontrollers](https://www.tensorflow.org/lite/microcontrollers)

## LICENSE
- [kendryte-standalone-sdk/LICENSE](https://github.com/kendryte/kendryte-standalone-sdk/blob/develop/LICENSE)
- [tensorflow/LICENSE](https://github.com/tensorflow/tensorflow/blob/master/LICENSE)
- [flatbuffers/LICENSE](src\micro\tensorflow\tensorflow\lite\micro\tools\make\downloads\flatbuffers\LICENSE.txt)
- [gemmlowp/LICENSE](src\micro\tensorflow\tensorflow\lite\micro\tools\make\downloads\gemmlowp\LICENSE)

## How to build

### Windows

Download and install latest CMake.

Download and install latest toolchain.

[Download kendryte-toolchain-win-i386-8.2.0-20190409.tar.xz](https://github.com/kendryte/kendryte-gnu-toolchain/releases/download/v8.2.0-20190409/kendryte-toolchain-win-i386-8.2.0-20190409.tar.xz)

Open a Windows Powershell, cd to Project directory (src\micro).

```powershell
> $env:Path="<PATH_TO_TOOLCHAIN>\kendryte-toolchain\bin;C:\Program Files\CMake\bin" +  $env:Path
> mkdir build && cd build
> cmake -G "MinGW Makefiles" ../../..
> make
```

You will get 2 key files, `micro` and `micro.bin`.

1. If you are using JLink to run or debug your program, use `micro`
2. If you want to flash it in UOG, using `micro.bin`, then using flash-tool(s) burn <ProjectName>.bin to your flash.

This is very important, don't make a mistake in files.
