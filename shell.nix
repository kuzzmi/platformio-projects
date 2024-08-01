{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = [
    pkgs.platformio
    pkgs.clang-tools
    pkgs.dfu-util
  ];

  PLATFORMIO_CORE_DIR = "${builtins.toString ./.}/.pio";
}
