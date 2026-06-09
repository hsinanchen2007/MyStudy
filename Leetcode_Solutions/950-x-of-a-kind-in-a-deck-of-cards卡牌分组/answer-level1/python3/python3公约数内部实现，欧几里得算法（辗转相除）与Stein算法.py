欧几里德算法又称辗转相除法， 用于计算两个整数a, b的最大公约数。其计算原理依赖于下面的定理：
定理： gcd(a, b) = gcd(b, a mod b)
证明：
  a可以表示成a = kb + r, 则r = a mod b
  假设d是a, b的一个公约数， 则有  d|a, d|b, 而r = a - kb, 因此d|r。
  因此，d是(b, a mod b)的公约数。
  加上d是(b，a mod b)的公约数，则d|b, d|r, 但是a = kb + r,因此d也是(a, b)的公约数。
  因此，(a, b) 和(a, a mod b)的公约数是一样的，其最大公约数也必然相等，得证。
欧几里德的Python语言描述为：
```
def gcd(a, b):
 if a < b:
  a, b = b, a

 while b != 0:
  temp = a % b
  a = b
  b = temp

 return a

```
欧几里德算法是计算两个数最大公约数的传统算法，无论是理论，还是从效率上都是很好的。但是他有一个致命的缺陷，这个缺陷只有在很大的素数时才会显现出来。
Stein算法也是计算两个数的最大公约数。和欧几里德算法不同的是，Stein算法只有整数的移位和加减法.
为了说明Stein算法的正确性，首先必须注意到以下结论：
  gcd(a, a) = a， 也就是一个数和他自己的公约数是其自身。
  gcd(ka, kb) = k * gcd(a, b)，也就是最大公约数运算和倍乘运算可以交换，特殊的，当k=2时，说明两个偶数的最大公约数比如能被2整除。
Stein算法的python实现如下：
```
def gcd_Stein(a, b):  
  if a < b:
    a, b = b, a
  if (0 == b):
    return a
  if a % 2 == 0 and b % 2 == 0:
    return 2 * gcd_Stein(a/2, b/2)
  if a % 2 == 0:
    return gcd_Stein(a / 2, b)
  if b % 2 == 0:
    return gcd_Stein(a, b / 2)
  
  return gcd_Stein((a + b) / 2, (a - b) / 2) 

```

