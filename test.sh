#!/usr/bin/env bash
set -euo pipefail

script_dir="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
binary="$(mktemp "${TMPDIR:-/tmp}/ferry-calculator.XXXXXX")"
trap 'rm -f -- "$binary"' EXIT

shopt -s nullglob
test_files=("$script_dir"/test*.txt)
if [[ ${#test_files[@]} -eq 0 ]]; then
  printf 'No test input files found.\n' >&2
  exit 1
fi

g++ -std=c++17 -Wall -Wextra -pedantic "$script_dir/main.cpp" -o "$binary"

for input_file in "${test_files[@]}"; do
  "$binary" < "$input_file"
  printf '\n'
done