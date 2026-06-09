#### 方法一：前缀和【通过】

**思路**

知道第 `i` 个字母最终移位多少次。

**算法**

因为对第 `i` 个字母及后面字母的移位都会导致第 `i` 个字母移位，所以第 `i` 个字母共移位 `shifts[i] + shifts[i+1] + ... + shifts[shifts.length - 1]` 次。

假设第 `i` 个字母移位 `X` 次，那么第 `i + 1` 个字母移位 `X - shifts[i]` 次。

例如 `S.length = 4`，那么 `S[0]` 移位 `X = shifts[0] + shifts[1] + shifts[2] + shifts[3]` 次，`S[1]` 移位 `shifts[1] + shifts[2] + shifts[3]` 次，`S[2]` 移位 `shifts[2] + shifts[3]` 次，以此类推。

当 `i` 增加时，令 `X -= shifts[i]` 计算下一个字母的移位次数。

```java [solution1-Java]
class Solution {
    public String shiftingLetters(String S, int[] shifts) {
        StringBuilder ans = new StringBuilder();
        int X = 0;
        for (int shift: shifts)
            X = (X + shift) % 26;

        for (int i = 0; i < S.length(); ++i) {
            int index = S.charAt(i) - 'a';
            ans.append((char) ((index + X) % 26 + 97));
            X = Math.floorMod(X - shifts[i], 26);
        }

        return ans.toString();
    }
}
```

```python [solution1-Python]
class Solution(object):
    def shiftingLetters(self, S, shifts):
        ans = []
        X = sum(shifts) % 26
        for i, c in enumerate(S):
            index = ord(c) - ord('a')
            ans.append(chr(ord('a') + (index + X) % 26))
            X = (X - shifts[i]) % 26

        return "".join(ans)
```


**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是 `S` 和 `shifts` 的长度。

* 空间复杂度：$O(N)$，存储移位后的字符串。