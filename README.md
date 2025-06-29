# C++ Competitive Programming Template

A comprehensive C++ template for competitive programming contests, containing utility functions, algorithms, and macros to speed up problem-solving.

## Features

### Macros and Shortcuts
- **Type definitions**: `ll` (long long), `unll` (unsigned long long), `ull`, `db` (long double)
- **Container operations**: `pb` (push_back), `mp` (make_pair), `all(v)`, `rall(v)`
- **Loop macro**: `f(i,j,k,l)` for custom loops
- **Output macros**: `aff(v)` (print vector), `affp(v)` (print pair vector), `yes`, `no`

### Mathematical Functions
- **Prime checking**: `prime(n)` - Check if a number is prime
- **Modular exponentiation**: `power(a, b)` - Calculate a^b mod MOD
- **Prime factorization**: `primeFactors(n)` - Get prime factors with their counts
- **GCD/LCM**: Built-in `lcm(a, b)` function
- **Digit sum**: `sum(n)` - Sum of digits of a number
- **Divisors**: `divisors(n)` - Get all divisors of a number

### Bit Manipulation
- **Count set bits**: `countNumBits1(mask)`
- **Binary representation**: `printNumber(n, s)` - Convert number to binary string
- **Even/odd counting**: `countp(a, b)` and `countimp(a, b)` for counting even/odd numbers in range

### String Algorithms
- **Longest substring**: `lengthoflongestsubstirng(st)` - Longest substring with unique characters
- **KMP preprocessing**: `longestprefixsuffix(s)` - Compute LPS array
- **String matching**: `rabin_karp(s, t)` - Find all occurrences of pattern in text
- **Subsequences**: `allSubsequences(input, subsequences)` - Generate all subsequences

### Array/Vector Utilities
- **XOR operations**: `maxXorSum(a)` - Maximum XOR sum in array
- **Custom comparators**: `comp` and `comp1` for sorting pairs

### Combinatorics
- **Factorials**: Precomputed factorial array
- **Modular arithmetic**: `mul()`, `add()`, `sub()`, `inv()` (modular inverse)
- **Binary exponentiation**: `binexp(a, k, mod)`
- **Combinations**: `Cnk(n, k)` - Calculate nCk mod MOD

### String Comparison
- **Hamming distance**: `compa(a, b)` - Count differing positions

## Constants
- `MOD = 1e9 + 7` - Standard modulo for competitive programming
- `N = 2e5 + 5` - Array size limit
- `P = 1e8 + 5` - Additional constant

## Usage

1. **Input/Output Setup**: 
   - Reads from `input.txt` and writes to `output.txt` when not in online judge
   - Fast I/O with `ios_base::sync_with_stdio(false)`

2. **Test Cases**: 
   - Supports multiple test cases with `int _ = 1; cin >> _;`

3. **Main Function**: 
   - Implement your solution in the `solve()` function

## Example Usage

```cpp
void solve() {
    ll n;
    cin >> n;
    
    // Check if prime
    if (prime(n)) {
        yes;
    } else {
        no;
    }
    
    // Get all divisors
    set<ll> divs = divisors(n);
    aff(divs);
}
```

## Notes
- Template includes `#include <bits/stdc++.h>` for convenience
- All functions are optimized for competitive programming time constraints
- Modular arithmetic functions use MOD = 1e9 + 7 by default
- String algorithms are case-sensitive and work with lowercase letters

## Author
BELKA

---
*This template is designed for competitive programming contests on Codeforces.*
