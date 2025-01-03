#!/usr/bin/python3

import sys
from pathlib import Path

regnames = [
    "zero", # 0

    "at", # 1

    "v0", # 2
    "v1", # 3

    "a0", # 4
    "a1", # 5
    "a2", # 6
    "a3", # 7

    "t0", # 8
    "t1", # 9
    "t2", # 10
    "t3", # 11
    "t4", # 12
    "t5", # 13
    "t6", # 14
    "t7", # 15

    "s0", # 16
    "s1", # 17
    "s2", # 18
    "s3", # 19
    "s4", # 20
    "s5", # 21
    "s6", # 22
    "s7", # 23
    
    "t8", # 24
    "t9", # 25
    
    "k0", # 26
    "k1", # 27
    
    "gp", # 28
    "sp", # 29
    "fp", # 30
    "ra", # 31
]

if len(sys.argv) < 2:
    print(f"Usage: {sys.argv[0]} [function name]")
    sys.exit(0)

func_name = sys.argv[1]
output_path = "out.s"

found_files = list(Path("asm/nonmatchings").rglob(f"{func_name}.s"))

if len(found_files) == 0:
    print(f"Could not find function {func_name}")
    sys.exit(1)

input_path = found_files[0]

with open(input_path, "r") as file:
    filedata = file.read()

for i in reversed(range(len(regnames))):
    filedata = filedata.replace(f"${i}", f"${regnames[i]}")

with open(output_path, "w") as file:
    file.write(filedata)

