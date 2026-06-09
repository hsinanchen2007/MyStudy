Notice：这是一篇伪数学的内容，严谨性和正确性似乎我都无法保证 quq。

最大公因数嘛，涉及到辗转相除法，即 `gcd(a, b) = gcd(b, a%b)`，那么对于这一题，自然就要定义好字符串的模运算了。

首先，根据题目，我们**假设 `str1` 与 `str2` 必定有最大公因数**，那么在这个前提下，可以得到 `str1 = m*T; str2 = n*T`，其中 `T` 为它们共同的最大公因数。

然后我们对 `T` 做做手脚，先来定义一个 sequence 函数，作用是不断循环输出 `T` 的所有字符，伪代码如下：

```javascript
function* c() {
    while (true)
        for (const ch of T)
            yield ch;
}

const _c = c()
function Seq() {
    return _c.next()
}
```

那么，`T = k*(Seq)`，这里我自己瞎定义了一个 `k*()` 操作，即对括号内的函数进行 `k` 次顺序调用。

`T` 的定义也有了，再回到 `str` 中来，把 `T` 定义直接代入，得到 `str1 = m*k*(Seq); str2 = n*k*(Seq)`，再让我们回想一下含义，`m, n` 表示有多少个 `T`，而 `k` 表示 `T` 有多少个字母，显然 `m*k = str1.length; n*k = str2.length`。因此我们得到了字符串与其长度关系的表达式，

```plain
str1 = str1.length * (Seq)
str2 = str2.length * (Seq)
```

好了！开始定义模运算吧，根据上面两条公式，有

```plain
str1 % str2
  = [str1.lenght * (Seq)] % [str2.length * (Seq)]
  = (str1.length % str2.length) * (Seq)
```

这里因为 `str1.length` 与 `str2.length` 均是 `k` 的倍数，即两者都可以完整地取完 `T`，那么这两个 `Seq` 函数状态必定是都指向 `T` 的首字母，因此可以提取出来。

这里可能我讲述的也不是很清楚，来举个栗子吧，例如 `str1 = "ABABAB"; str2 = "ABAB"`，那么 `T = "AB"`，函数 `Seq` 则是不断地去生成 `'A', 'B'` 这两个字母序列，那么：

```plain
str1 % str2
  = [6 * (Seq)] % [4 * (Seq)]
  = "ABABAB" % "ABAB"
  = "AB"  # 这里可以理解为 "ABABAB" / "ABAB" 在约去共同的 "ABAB" 之后的余“数”

str1 % str2
  = (6 % 4) * (Seq)
  = 2 * (Seq)
  = "AB"
```

因此，`(Seq)` 在一开始拥有最大公因数的前提下是可以被提取出来的。

这样一来，字符串模运算已经定义完了，即 `str1 % str2 = (str1.length % str2.length) * (Seq)`，我们开始将它代入辗转相除公式 `gcd()` 中

```plain
gcd(str1, str2)
  = gcd(str2, str1 % str2)
  = gcd(str2, (str1.length % str2.length) * (Seq))
  = gcd(str2.length * (Seq), (str1.length % str2.length) * (Seq))
  = gcd(str2.length, str1.length % str2.length) * (Seq)  # <==
  = gcd(str1.length, str2.length) * (Seq)
```

Wow，这样我们就自然地将原本要求的 `gcd(str1, str2)` 转成了大家更加熟悉的 `gcd(str1.length, str2.length)` 了!

注意上面标 `# <==` 的公式，为啥这里也能提取 `(Seq)` 呢？大家想一下 `gcd()` 的定义，即求最大公约数，那么 `gcd(a*c, b*c)` 中 `c` 显然就是一个公约数，而且当我们求出了 `a,b` 之间的最大公因数后，别忘了它们曾经还乘了个 `c`，因此很明显 `gcd(a*c, b*c) = gcd(a, b) * C)`（这等式是我通过强行验算得到的，应该不太严谨 orz）。

好了，关系式我们有了，而且前半部分我们也能计算出来，那么后面的 `(Seq)` 呢？回想起前提，可以发现其实 `(Seq)` 就是 `str1 or str2` 的子集，而且只由 `(Seq)` 组成。而且根据 `gcd()`，我们可以断言 `(str1.length or str2.length) <= gcd(str1.length, str2.length)`，因此可以放心大胆地用 `str1 or str2` 直接代替掉 `(Seq)`。

这样一来，除了前提外计算条件都有了，那么前提我们应该怎么满足呢？这里就借用官方题解的话

> 需要知道一个性质：如果 str1 和 str2 拼接后等于 str2和 str1 拼接起来的字符串（注意拼接顺序不同），那么一定存在符合条件的字符串 X。

这里的 `X` 即是我们需要的 `T`。

万事具备！开始写代码！

```kotlin
class Solution {
    fun gcdOfStrings(str1: String, str2: String): String {
        // 确保 str1 与 str2 拥有最大公因子
        if (str1 + str2 != str2 + str1) {
            return ""
        }

        // 既然有最大公因子，那么由上述，gcd(str1, str2) = gcd(str1.length, str2.length) * (Seq)
        // 又因为 (Seq) 可以直接使用 str1 表示，那么上述就等价与取 str1 长度为 gcd() 的子串（仔细想一想）
        return str1.substring(0, gcd(str1.length, str2.length))
    }

    private tailrec fun gcd(a: Int, b: Int): Int {
        if (b == 0) {
            return a
        }
        return gcd(b, a % b)
    }
}
```
