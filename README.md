# CPP Module 06

C++ type casting exercises from the 42 curriculum. This module covers
`static_cast`, `reinterpret_cast`, and `dynamic_cast` through three exercises.

## Technologies

- C++98
- Makefile

## Build

Each exercise is compiled independently from its own directory:

```bash
cd ex00 && make   # ScalarConverter
cd ex01 && make   # Serializer
cd ex02 && make   # Type identification
```

Common Makefile targets: `make`, `make clean`, `make fclean`, `make re`.

## Usage

### ex00 -- Scalar Type Conversion

Converts a string literal to `char`, `int`, `float`, and `double`.

```bash
./convert 42
./convert 4.2f
./convert nan
./convert "a"
```

### ex01 -- Serialization

Serializes a `Data*` pointer to `uintptr_t` and back using `reinterpret_cast`,
then verifies pointer integrity.

```bash
./serializer
```

### ex02 -- Dynamic Type Identification

Randomly generates objects of type A, B, or C (derived from Base) and
identifies their actual type using `dynamic_cast` on both pointers and
references.

```bash
./identify
```

## Key Concepts

- **static_cast** -- safe, compile-time checked conversions between scalar types
- **reinterpret_cast** -- low-level reinterpretation of pointer/integer types
- **dynamic_cast** -- runtime polymorphic type identification (RTTI)
- Non-instantiable utility classes with private constructors
- Exception-based type detection via failed reference casts
