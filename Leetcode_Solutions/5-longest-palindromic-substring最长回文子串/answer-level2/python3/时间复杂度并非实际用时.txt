### 解题思路

- 最开始想到的是暴力法，从最长子串开始查找，是回文字符串则返回，然后用时8000ms
- 看了官方的解释，暴力法时间复杂度`O(n^3)`，子串数量是`n(n+1)/2`,判断比较子串的每个字符需要`O(n)`
- 官方介绍了五种算法，中心扩展的时间复杂度为`O(n^2)`,使用该方法后用时1500ms，有改进但仍然较大
- 还有一种[Manacher算法](https://oi-wiki.org/string/manacher/)，是线性时间，遍历每个字符时记录扩展的最大回文子串，如果下一个字符在最大回文子串当中，该字符与在最大回文子串对称位置的字符拥有相同的扩展，这样可以减少一些无效的迭代，使用该算法后用时600ms
- 观摩了一种排名靠前的算法，用时60ms，所用仍是中心扩展法，即时间复杂度为`O(n^2)`
- 之所以如此，是因为算法时间复杂度并不等同于实际用时，数据量较小时，时间复杂度高的算法可能处理操作小于时间复杂度低的算法。题目限定，s最大长度为1000，出现这种情况，也就可以理解了。

### 代码

#### 用时60ms中心扩展，使用双指针遍历
```python3
class Solution:
    def longestPalindrome(self, s: str) -> str:
        """找到最长回文子串"""
        left = 0
        right = 0
        n = len(s)
        p1 = p2 = ''
        while right < n:
            if left > -1 and s[left:right + 1] == s[left:right + 1][::-1]:
                p1 = s[left:right + 1]
                right += 1
                left -= 1
            else:
                right += 1
                left += 1

        left = 0
        right = 1
        while right < n:
            if left > -1 and s[left:right + 1] == s[left:right + 1][::-1]:
                p2 = s[left:right + 1]
                right += 1
                left -= 1
            else:
                right += 1
                left += 1

        return p1 if len(p1) > len(p2) else p2
```

#### 用时1500ms中心扩展，找出每个字符扩展的最大回文子串

```python3
def longest_palindrome(s):
    """找到最长回文子串"""
    if not s:
        return ""
    l = len(s)
    d1 = [1 for i in range(l)]
    d2 = [0 for i in range(l)]
    for i in range(l):
        while 0 <= i - d1[i] and i + d1[i] < l and s[i - d1[i]] == s[i + d1[i]]:
            d1[i] += 1
        while 0 <= i - d2[i] - 1 and i + d2[i] < l and s[i - d2[i] - 1] == s[i + d2[i]]:
            d2[i] += 1
    max_d1 = max(d1)
    max_d2 = max(d2)
    max_d1_index = d1.index(max_d1)
    max_d2_index = d2.index(max_d2)
    return s[max_d1_index-max_d1+1:max_d1_index + max_d1] if max_d1 >= max_d2 + 1 \
        else s[max_d2_index - max_d2:d2.index(max_d2) + max_d2]
```

#### 用时600ms,manacher算法，找出每个字符扩展的最大回文子串

```python3
def longest_palindrome(s):
    """找到最长回文子串"""
    if not s:
        return ""
    l = len(s)
    d1 = [1 for i in range(l)]
    d2 = [0 for i in range(l)]
    b, r = 0, -1
    b2, r2 = 0, -1
    for i in range(0, l):
        k = 1 if i > r else min(d1[b + r - i], r - i)
        while 0 <= i - k and i + k < l and s[i - k] == s[i + k]:
            k += 1
        d1[i] = k - 1
        if i + k > r:
            b = i - k
            r = i + k
    
        k = 0 if i > r2 else min(d2[b2 + r2 - i + 1], r2 - i + 1)
        while 0 <= i - k - 1 and i + k < l and s[i - k - 1] == s[i + k]:
            k += 1
        d2[i] = k - 1
        if i + k > r2:
            b2 = i
            r2 = i
    max_d1 = max(d1)
    max_d2 = max(d2)
    max_d1_index = d1.index(max_d1)
    max_d2_index = d2.index(max_d2)
    return s[max_d1_index-max_d1:max_d1_index + max_d1 + 1] if max_d1 >= max_d2 + 1\
        else s[max_d2_index - max_d2 - 1:d2.index(max_d2) + max_d2 + 1]
```

#### 用时8000ms的暴力算法....

```python3
def longest_palindrome(s):
    """找到最长回文子串"""
    if not s:
        return ""
    def is_palindrome(s):
        l = len(s)
        if l % 2 == 0:
            return s[:int(l/2)] == s[:int(l/2)-1:-1]
        else:
            return s[:int(l/2) + 1] == s[:int(l/2)-1:-1]


    i = l
    while i > 1:
        j = 0
        while j + i <= l:
            sub = s[j:j + i]
            if is_palindrome(sub):
                return sub
            j += 1
        i -= 1
    return s[0]
```
