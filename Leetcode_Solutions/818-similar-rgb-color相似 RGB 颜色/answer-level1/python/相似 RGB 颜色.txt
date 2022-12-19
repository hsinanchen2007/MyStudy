#### 方法一：枚举

由于从 `#000` 到 `#fff` 一共只有 `16^3 = 4096` 种颜色，因此我们可以枚举这些颜色，并计算其与 `color` 的相似度。

在枚举所有的颜色时，我们可以使用三重循环，每一重循环的范围为 `0` 到 `15`。设三重循环分别为 `R`，`G` 和 `B`，那么其对应的颜色的十六进制值为 `17 * R * (1 << 16) + 17 * G * (1 << 8) + 17 * B`，这里的 `17` 由 `0x11 = 16 + 1 = 17` 得来，`(1 << 16)` 和 `(1 << 8)` 分别为 `R` 和 `G` 的左移位数。

在计算两种颜色的相似度时，我们从其十六进制值可以得到三种颜色对应的值，即 `r = (hex >> 16) % 256`，`g = (hex >> 8) % 256` 以及 `b = hex % 256`。随后通过 `(r1 - r2)^2 + (g1 - g2)^2 + (b1 - b2)^2` 计算相似度。

在枚举完所有的颜色后，我们需要将答案转换为 `16` 进制输出，此时可以用 `Java` 或 `Python` 中的 `format`，用 `06x` 表示输出为 `6` 位的十六进制数（`x` 表示十六进制），且少于 `6` 位的高位补 `0`。

```Java [sol1]
class Solution {
    public String similarRGB(String color) {
        int hex1 = Integer.parseInt(color.substring(1), 16);
        int ans = 0;
        for (int r = 0; r < 16; ++r)
            for (int g = 0; g < 16; ++g)
                for (int b = 0; b < 16; ++b) {
                    int hex2 = 17 * r * (1 << 16) + 17 * g * (1 << 8) + 17 * b;
                    if (similarity(hex1, hex2) > similarity(hex1, ans))
                        ans = hex2;
                }

        return String.format("#%06x", ans);
    }

    public int similarity(int hex1, int hex2) {
        int ans = 0;
        for (int shift = 16; shift >= 0; shift -= 8) {
            int col1 = (hex1 >> shift) % 256;
            int col2 = (hex2 >> shift) % 256;
            ans -= (col1 - col2) * (col1 - col2);
        }
        return ans;
    }
}
```

```Python [sol1]
class Solution(object):
    def similarRGB(self, color):
        def similarity(hex1, hex2):
            r1, g1, b1 = hex1 >> 16, (hex1 >> 8) % 256, hex1 % 256
            r2, g2, b2 = hex2 >> 16, (hex2 >> 8) % 256, hex2 % 256
            return -(r1 - r2)**2 - (g1 - g2)**2 - (b1 - b2)**2

        hex1 = int(color[1:], 16)
        ans = 0
        for r in xrange(16):
            for g in xrange(16):
                for b in xrange(16):
                    hex2 = 17 * r * (1 << 16) + 17 * g * (1 << 8) + 17 * b
                    if similarity(hex1, hex2) > similarity(hex1, ans):
                        ans = hex2

        return '#{:06x}'.format(ans)
```

**复杂度分析**

* 时间复杂度：$O(1)$。

* 空间复杂度：$O(1)$。

#### 方法二：独立性 + 枚举

我们可以发现，颜色中的每一维都是独立的，因此我们只需要分别计算出 `color = #ABCDEF` 中与 `AB`，`CD` 和 `EF` 相似度最大的颜色即可。最终的答案为这三个颜色的结合。

对于 `AB`，我们要在 `00` 到 `ff` 中找到一个相似度最大的。在方法一中我们得知，`00` 到 `ff` 均为 `17` 的倍数，因此我们需要找到一个 `17` 的倍数，使得其与 `AB` 的差的绝对值最小。显然，当 `AB mod 17 > 8` 时，取刚好比 `AB` 大的那个数；当 `AB mod 17 <= 8` 时，取刚好比 `AB` 小或与 `AB` 相等的那个数。

```Java [sol2]
class Solution {
    public String similarRGB(String color) {
        return "#" + f(color.substring(1, 3)) + f(color.substring(3, 5)) + f(color.substring(5));
    }

    public String f(String comp) {
        int q = Integer.parseInt(comp, 16);
        q = q / 17 + (q % 17 > 8 ? 1 : 0);
        return String.format("%02x", 17 * q);
    }
}
```

```Python [sol2]
class Solution(object):
    def similarRGB(self, color):
        def f(comp):
            q, r = divmod(int(comp, 16), 17)
            if r > 8: q += 1
            return '{:02x}'.format(17 * q)

        return '#' + f(color[1:3]) + f(color[3:5]) + f(color[5:])
```

**复杂度分析**

* 时间复杂度：$O(1)$。

* 空间复杂度：$O(1)$。