#### 方法一：哈希表

**直觉**

最直接的方法是，首先从字母中构造尽可能多的 `“zero”`，然后再构造尽可能多的 `“one”`，以此类推。问题在于，字母 `“o”`，`“n”`，`“e”` 都可以在其他的数字中出现，这意味着直接的方法可能会带来一些问题。

![image.png](https://pic.leetcode-cn.com/d315ee51e4e72ac28db0508b10787b19993509ddd62010491639719cc6e364f1-image.png){:width=600}
{:align=center}


因此，我们需要寻找一些独特的标志。注意到，所有的偶数都包含一个独特的字母：

* `“z”` 只在 `“zero”` 中出现。
* `“w”` 只在 `“two”` 中出现。
* `“u”` 只在 `“four”` 中出现。
* `“x”` 只在 `“six”` 中出现。
* `“g”` 只在 `“eight”` 中出现。

> 因此，从偶数开始是一个很好的思路。

这也是计算 `3`，`5` 和 `7` 的关键，因为有些单词只在一个奇数和一个偶数中出现（而且偶数已经被计算过了）：

* `“h”` 只在 `“three”` 和 `“eight”` 中出现。
* `“f”` 只在 `“five”` 和 `“four”` 中出现。
* `“s”` 只在 `“seven”` 和 `“six”` 中出现。

接下来只需要处理 `9`和 `0`，思路依然相同。

* `“i”` 在 `“nine”`，`“five”`，`“six”` 和 `“eight” `中出现。
* `“n”` 在 `“one”`，`“seven”` 和 `“nine”` 中出现。

**实现**

<![image.png](https://pic.leetcode-cn.com/7a77404614bf9b4f3ac773cc5dab8f6a9bc9e5a4ac893dc680e2381167750899-image.png),![image.png](https://pic.leetcode-cn.com/2b862100f4d21b2164f7c5de54ea8e58cdf1fcf852bc2575a65a5dcf336904c4-image.png),![image.png](https://pic.leetcode-cn.com/cedb95df02c5e411a14b6f83fef26aab530419de47c39786c6ff746097776b04-image.png),![image.png](https://pic.leetcode-cn.com/75d2f92b489eb8d2d51066b2731fdd6d2e42a0e5a10ae34be198216799baf3de-image.png),![image.png](https://pic.leetcode-cn.com/e7a1e19a0ad228999fb662ac9d5ddf9a149fae7a349b309344aa437536c0dcad-image.png),![image.png](https://pic.leetcode-cn.com/49a746f6f26247fca400ad06e4bde8de437363ce21b8202a0648403ce48523ef-image.png),![image.png](https://pic.leetcode-cn.com/c281c3232b90b6d0c3d3b8e86ce958993f71ac68b7dd190f2b8a197523fb7c5a-image.png),![image.png](https://pic.leetcode-cn.com/6f2f880010dea8c1697118713e91ab02f1b7c224c59865f01a14174b09b1d38e-image.png),![image.png](https://pic.leetcode-cn.com/81fb4b2d4a8d6d875ac9fffd02686e61eb5d621a8b4430181fffc0b95983701a-image.png),![image.png](https://pic.leetcode-cn.com/653181cb1d354d555d398e3dfa817b12bc58ba7c16dda4429ef02ae3712a9067-image.png),![image.png](https://pic.leetcode-cn.com/f6290875482dfaf92b7d6110bf5050fc58a59a331c04a28d1a29ad151f34e760-image.png),![image.png](https://pic.leetcode-cn.com/edbaa74bd7875f333a437c338f5a51aa6cbfe65c292d34766485b193349960cb-image.png)>

```Java [solution 1]
class Solution {
  public String originalDigits(String s) {
    // building hashmap letter -> its frequency
    char[] count = new char[26 + (int)'a'];
    for(char letter: s.toCharArray()) {
      count[letter]++;
    }

    // building hashmap digit -> its frequency
    int[] out = new int[10];
    // letter "z" is present only in "zero"
    out[0] = count['z'];
    // letter "w" is present only in "two"
    out[2] = count['w'];
    // letter "u" is present only in "four"
    out[4] = count['u'];
    // letter "x" is present only in "six"
    out[6] = count['x'];
    // letter "g" is present only in "eight"
    out[8] = count['g'];
    // letter "h" is present only in "three" and "eight"
    out[3] = count['h'] - out[8];
    // letter "f" is present only in "five" and "four"
    out[5] = count['f'] - out[4];
    // letter "s" is present only in "seven" and "six"
    out[7] = count['s'] - out[6];
    // letter "i" is present in "nine", "five", "six", and "eight"
    out[9] = count['i'] - out[5] - out[6] - out[8];
    // letter "n" is present in "one", "nine", and "seven"
    out[1] = count['n'] - out[7] - 2 * out[9];

    // building output string
    StringBuilder output = new StringBuilder();
    for(int i = 0; i < 10; i++)
      for (int j = 0; j < out[i]; j++)
        output.append(i);
    return output.toString();
  }
}
```

```Python [solution 1]
class Solution:
    def originalDigits(self, s: 'str') -> 'str':
        # building hashmap letter -> its frequency
        count = collections.Counter(s)
        
        # building hashmap digit -> its frequency 
        out = {}
        # letter "z" is present only in "zero"
        out["0"] = count["z"]
        # letter "w" is present only in "two"
        out["2"] = count["w"]
        # letter "u" is present only in "four"
        out["4"] = count["u"]
        # letter "x" is present only in "six"
        out["6"] = count["x"]
        # letter "g" is present only in "eight"
        out["8"] = count["g"]
        # letter "h" is present only in "three" and "eight"
        out["3"] = count["h"] - out["8"]
        # letter "f" is present only in "five" and "four"
        out["5"] = count["f"] - out["4"]
        # letter "s" is present only in "seven" and "six"
        out["7"] = count["s"] - out["6"]
        # letter "i" is present in "nine", "five", "six", and "eight"
        out["9"] = count["i"] - out["5"] - out["6"] - out["8"]
        # letter "n" is present in "one", "nine", and "seven"
        out["1"] = count["n"] - out["7"] - 2 * out["9"]

        # building output string
        output = [key * out[key] for key in sorted(out.keys())]
        return "".join(output)
```


**复杂度分析**

* 时间复杂度 : ${O}(N)$，其中 `N` 为输入字符串中的字符数。计算哈希表需要 ${O}(N)$ 的时间。下一步处理只有 `10` 个元素的 `out` 只需要常数时间。
* 空间复杂度 : ${O}(1)$。
由于输入字符串只包括英文小写字母，`count` 包含常数个元素，而 `out` 也只需要 `10` 个元素。
