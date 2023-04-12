# Mirror-Hash (WIP)

## DISCLAIMER: Experimental, do not use in production!

Mirror-Hash is an experimental hashing algorithm designed for use with optical/quantum computers. It is based on Toffoli and Fredkin gates and uses a unique structure that includes 64 layers of gates, each consisting of two sublayers of Toffoli or Fredkin gates in a zig-zag pattern. The symmetry (mirrored or not) and type of gate used is determined by the previous block of the hash (called the layer encoding), and there is also an XOR operation with the current layer encoding to avoid 0-to-0 hashes.

## Hashing Algorithm
The Mirror-Hash algorithm has the following characteristics:

- Standard 256-bit input
- 64 layers of gates
- Each layer has 2 sublayers of Toffoli or Fredkin gates in zig-zag fashion
- The symmetry (mirrored or not) and type of gate (Toffoli or Fredkin) is determined by the previous block (called layer encoding here) of the hash
- XOR operation with the current layer encoding to avoid 0-to-0 hashes

Here's a ASCI diagram in Markdown for the gate grid specification:

| Gate type | Symbol | Encoding |
|-----------|--------|----------|
| Toffoli   |   #    |    00    |
| Mirrored Toffoli   |   #̅   |    01    |
| Fredkin   |   @    |    10    |
| Mirrored Fredkin   |   @̅   |    11    |

| Layer | Column 1 | Column 2 | Column 3 | Column 4 | Column 5 | Column 6 | Column 7 | Column 8 |
|-------|----------|----------|----------|----------|----------|----------|----------|----------|
|   1   |   ###    |   @@@    |   ###    |   @@@    |   ###    |   @@@    |   ###    |   @@@    |
|   2   |   ###    |          |   ###    |          |   ###    |          |   ###    |          |
|   3   |   ###    |   @@@    |   ###    |   @@@    |   ###    |   @@@    |   ###    |   @@@    |
|   4   |          |   @@@    |          |   @@@    |          |   @@@    |          |   @@@    |
|   5   |   ###    |   @@@    |   ###    |   @@@    |   ###    |   @@@    |   ###    |   @@@    |
|   6   |   ###    |          |   ###    |          |   ###    |          |   ###    |          |
|   7   |   ###    |   @@@    |   ###    |   @@@    |   ###    |   @@@    |   ###    |   @@@    |
|   8   |          |   @@@    |          |   @@@    |          |   @@@    |          |   @@@    |
|  ...  |   ...    |    ...   |    ...   |    ...   |    ...   |    ...   |    ...   |    ...   |
|  64   |   ###    |   @@@    |   ###    |   @@@    |   ###    |   @@@    |   ###    |   @@@    |


## Usage
To use Mirror-Hash, you can run the mirror.py script using Python 2. There are still some bugs to fix, as the algorithm works well with random input but not with non-random input. The script currently generates 25 hashes per second.

## Example
Here is an example of how to use Mirror-Hash:

```bash
cat "Hola, mundo." > input.txt
./mirror256_test input.txt
0xabbaabba...
```
