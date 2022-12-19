#### 方法一：递归【通过】

**思路**

从左往右依次遍历字符，过程中保持 `ans` 为已遍历过字符的字母大小全排列。

例如，当 `S = "abc"` 时，考虑字母 `"a", "b", "c"`，初始令 `ans = [""]`，依次更新 `ans = ["a", "A"]`， `ans = ["ab", "Ab", "aB", "AB"]`， `ans = ["abc", "Abc", "aBc", "ABc", "abC", "AbC", "aBC", "ABC"]`。

**算法**

如果下一个字符 `c` 是字母，将当前已遍历过的字符串全排列复制两份，在第一份的每个字符串末尾添加 `lowercase(c)`，在第二份的每个字符串末尾添加 `uppercase(c)`。

如果下一个字符 `c` 是数字，将 `c` 直接添加到每个字符串的末尾。

```java [solution1-Java]
class Solution {
    public List<String> letterCasePermutation(String S) {
        List<StringBuilder> ans = new ArrayList();
        ans.add(new StringBuilder());

        for (char c: S.toCharArray()) {
            int n = ans.size();
            if (Character.isLetter(c)) {
                for (int i = 0; i < n; ++i) {
                    ans.add(new StringBuilder(ans.get(i)));
                    ans.get(i).append(Character.toLowerCase(c));
                    ans.get(n+i).append(Character.toUpperCase(c));
                }
            } else {
                for (int i = 0; i < n; ++i)
                    ans.get(i).append(c);
            }
        }

        List<String> finalans = new ArrayList();
        for (StringBuilder sb: ans)
            finalans.add(sb.toString());
        return finalans;
    }
}
```

```python [solution1-Python]
class Solution(object):
    def letterCasePermutation(self, S):
        ans = [[]]

        for char in S:
            n = len(ans)
            if char.isalpha():
                for i in xrange(n):
                    ans.append(ans[i][:])
                    ans[i].append(char.lower())
                    ans[n+i].append(char.upper())
            else:
                for i in xrange(n):
                    ans[i].append(char)

        return map("".join, ans)
```

**复杂度分析**

* 时间复杂度：$O(2^{N} * N)$，其中 $N$ 是 `S` 的长度。

* 空间复杂度：$O(2^N * N)$。

#### 方法二：二分掩码【通过】

**思路**

假设字符串 `S` 有 $B$ 个字母，那么全排列就有 $2^B$ 个字符串，且可以用位掩码 `bits` 唯一地表示。

例如，可以用 `00` 表示 `a7b`， `01` 表示 `a7B`， `10` 表示 `A7b`， `11` 表示 `A7B`。注意数字不是掩码的一部分。

**算法**

根据位掩码，构造正确的全排列结果。如果下一个字符是字母，则根据位掩码添加小写或大写字母。 否则添加对应的数字。

```java [solution2-Java]
class Solution {
    public List<String> letterCasePermutation(String S) {
        int B = 0;
        for (char c: S.toCharArray())
            if (Character.isLetter(c))
                B++;

        List<String> ans = new ArrayList();

        for (int bits = 0; bits < 1<<B; bits++) {
            int b = 0;
            StringBuilder word = new StringBuilder();
            for (char letter: S.toCharArray()) {
                if (Character.isLetter(letter)) {
                    if (((bits >> b++) & 1) == 1)
                        word.append(Character.toLowerCase(letter));
                    else
                        word.append(Character.toUpperCase(letter));
                } else {
                    word.append(letter);
                }
            }

            ans.add(word.toString());
        }

        return ans;

    }
}
```

```python [solution2-Python]
class Solution(object):
    def letterCasePermutation(self, S):
        B = sum(letter.isalpha() for letter in S)
        ans = []

        for bits in xrange(1 << B):
            b = 0
            word = []
            for letter in S:
                if letter.isalpha():
                    if (bits >> b) & 1:
                        word.append(letter.lower())
                    else:
                        word.append(letter.upper())

                    b += 1
                else:
                    word.append(letter)

            ans.append("".join(word))
        return ans
```


**复杂度分析**

* 时间和空间复杂度：$O(2^{N} * N)$，与方法一分析相同。

#### 方法三： 内置函数库【通过】

**思路和算法**

集合的笛卡尔乘积是从所有集合中选择每种可能的组合。例如 `{1, 2
} x {a, b, c} = {1a, 1b, 1c, 2a, 2b, 2c}`。

对于具有内置函数来计算笛卡尔积的语言，可以直接调用内置函数减少工作量。

```python [solution3-Python]
class Solution(object):
    def letterCasePermutation(self, S):
        f = lambda x: (x.lower(), x.upper()) if x.isalpha() else x
        return map("".join, itertools.product(*map(f, S)))
```

**复杂度分析**

* 时间和空间复杂度：$O(2^{N} * N)$，与方法一分析相同。