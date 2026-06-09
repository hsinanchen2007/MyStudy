#### 方法一：桶记数

**思路**

我们可以开一个长度为 26 的数组表示 26 个桶，每个桶里存放一种字母。先用 $O(|s|)$ 的时间扫描一遍字符串（其中 $|s|$ 代表字符串的长度），统计每个字母出现的次数。然后我们只要不停地扫描这里的「桶序列」——先从小到大扫，再从大到小扫，每次发现一个桶当中计数值不为 0 的时候，就把这个桶对应的字母添加到结果字符串的最后方，然后对计数值减一。

具体地，开一个长度为 26 的数组 `h[]`，作为用来计数的「桶」。`haveChar` 的功能是在每次循环开始执行之前判断是否还有未使用的字符。`appendChar` 的功能是检测当前位置的桶是否计数值为 0，如果不为 0 则修改目标串和计数值。

**代码**

```cpp [sol1]
class Solution {
public:
    int h[26];

    inline bool haveChar() {
        for (int i = 0; i < 26; ++i) {
            if (h[i]) {
                return true;
            }
        }
        return false;
    }

    string sortString(string s) {
        for (const auto &c: s) ++h[c - 'a'];

        string ret;

        auto appendChar = [&] (int p) {
            if (h[p]) {
                --h[p];
                ret.push_back(p + 'a');
            }
        };

        while (true) {
            if (!haveChar()) break;
            for (int i = 0; i < 26; ++i) appendChar(i);
            for (int i = 25; i >= 0; --i) appendChar(i);
        }

        return ret;
    }
};
```

```python [sol1]
class Solution:
    def sortString(self, s: str) -> str:
        h = [0] * 26
        for ch in s:
            h[ord(ch) - 97] += 1

        def appendChar(ret, p):
            if h[p] > 0:
                h[p] -= 1
                ret.append(chr(p + 97))
        
        def haveChar():
            return any(h[i] > 0 for i in range(26))
        
        ret = list()
        while True:
            if not haveChar():
                break
            for i in range(26):
                appendChar(ret, i)
            for i in range(26):
                appendChar(ret, 25 - i)
        return "".join(ret)
```

**复杂度分析**

- 时间复杂度：考虑最坏情况下字符串 $s$ 中 $|s|$ 个字符全部是同一个字母，最外层的 `while` 循环就要执行 $\lceil \frac{|s|}{2} \rceil$ 次（其中 $\lceil x \rceil$ 表示 $x$ 向上取整），每次执行中又包含 3 个执行 26 次的循环，故这里的渐进时间复杂度为 $O(3 \times 26 \times |s|) = O(|s|)$。

- 空间复杂度：这里使用了长度为 26 的数组作为辅助空间，故渐进空间复杂度为 $O(26)$。