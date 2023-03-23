# Building RISK-XVII from Source

# Linux

Dependencies: `gcc, make`

```shell
cd RISK-XVII-PROGRAM/src
make
sudo make install
# alternatively, move the compiled binary to your preferred location
```

# Windows

There are two avenues to using RISK-XVII on Windows. The first (and recommended) 
was is to install Windows Subsystem Linux, in which case the instructions will
be exactly the same as on Linux. The second way is to download a zip file from
Github, extract the files, and use either MinGW or Cygwin to build RISK-XVII.

```shell
cd RISK-XVII-PROGRAM\\src
# invoke the version of make installed on your system
# add the resulting 'riskxvii.exe' to your windows path
```

# Mac OSX

Dependencies: `xcode command line tools`

```shell
xcode-select --install
cd RISK-XVII-PROGRAM/src
make
sudo make install
# alternatively, move the compiled binary to your preferred location
```
