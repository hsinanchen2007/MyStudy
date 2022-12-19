在 O(log n) 非尾递归算法[1]的基础上利用关系 (a \* (b / 2)) \* 2 = (a \* 2) \* (b / 2)，引入一个额外的变量 prod，在整个递归过程中保持 a * b + prod 不变，最后返回 prod。可以得到尾递归的算法：

```C++
int multiply(int A, int B) {
  return __mul(A, B, 0);
}

int __mul(int A, int B, int prod) {
  if (B == 0) return prod;
  // A * (B - 1) + (prod + A) = A * B + prod
  if (B % 2 == 1) return __mul(A, B - 1, prod + A);
  // (A * 2) * (B / 2) + prod = A * B + prod
  else            return __mul(A << 1, B >> 1, prod);
}
```

[1] 即

```C++
int multiply(int A, int B) {
  if (B == 0) return 0;
  if (B % 2 == 1) return A + multiply(A, B - 1);
  else            return multiply(A, B / 2) << 1;
}
```