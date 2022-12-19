#### 方法：逆向工作法

**思路**

如果我们有一个像 `appleappleappleappleappleapple` 这样的解码字符串和一个像 `K=24` 这样的索引，那么如果 `K=4`，答案是相同的。

一般来说，当解码的字符串等于某个长度为 `size` 的单词重复某些次数（例如 `apple` 与 `size=5` 组合重复6次）时，索引 `K` 的答案与索引 `K % size` 的答案相同。

我们可以通过逆向工作，跟踪解码字符串的大小来使用这种洞察力。每当解码的字符串等于某些单词 `word` 重复 `d` 次时，我们就可以将 `k` 减少到 `K % (Word.Length)`。

**算法**

首先，找出解码字符串的长度。之后，我们将逆向工作，跟踪 `size`：解析符号 `S[0], S[1], ..., S[i]` 后解码字符串的长度。

如果我们看到一个数字 `S [i]`，则表示在解析 `S [0]，S [1]，...，S [i-1]` 之后解码字符串的大小将是 `size / Integer(S[i])`。 否则，将是 `size - 1`。

```cpp [2ooN4yc4-C++]
class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long size = 0;
        int N = S.size();

        // Find size = length of decoded string
        for (int i = 0; i < N; ++i) {
            if (isdigit(S[i]))
                size *= S[i] - '0';
            else
                size++;
        }

        for (int i = N-1; i >=0; --i) {
            K %= size;
            if (K == 0 && isalpha(S[i]))
                return (string) "" + S[i];

            if (isdigit(S[i]))
                size /= S[i] - '0';
            else
                size--;
        }
        return "";
    }
};
```
```java [2ooN4yc4-Java]
class Solution {
    public String decodeAtIndex(String S, int K) {
        long size = 0;
        int N = S.length();

        // Find size = length of decoded string
        for (int i = 0; i < N; ++i) {
            char c = S.charAt(i);
            if (Character.isDigit(c))
                size *= c - '0';
            else
                size++;
        }

        for (int i = N-1; i >= 0; --i) {
            char c = S.charAt(i);
            K %= size;
            if (K == 0 && Character.isLetter(c))
                return Character.toString(c);

            if (Character.isDigit(c))
                size /= c - '0';
            else
                size--;
        }

        throw null;
    }
}
```
```python [2ooN4yc4-Python]
class Solution(object):
    def decodeAtIndex(self, S, K):
        size = 0
        # Find size = length of decoded string
        for c in S:
            if c.isdigit():
                size *= int(c)
            else:
                size += 1

        for c in reversed(S):
            K %= size
            if K == 0 and c.isalpha():
                return c

            if c.isdigit():
                size /= int(c)
            else:
                size -= 1
```


**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是 `S` 的长度。
* 空间复杂度：$O(1)$。