### 解题思路
中心思想：对数组中的每个元素分别把他们当做中心，并扩散查找与之相邻的两个字符是否相等，如果相等则继续扩大两边的查找范围，此算法复杂度应是O(n^2)

注意以下要点
1. 首尾的字符不需要遍历，即s[0]和s[len(s)]
2. 当回文是奇数长度，没什么问题，但是当回文是偶数长度，如"baab"，那么算法就会出错，因此，需要对原字符串进行修补，在首尾增加特殊字符，在每两个字符中间也增加特殊字符，对这个处理过的字符串进行遍历
3. 增加了特殊字符（比如'#'）后，原字符串里如果是回文，一样能挑出来，是等效的，不是回文也会忽略，所以不会影响到回文的查找，最后查找完之后再把result中的特殊字符去掉即可
4. 在首尾增加特殊字符还有个好处，就是遇到长度为1或者长度为2的字符串，也能输出结果，比如"a" -> "a", "bb" -> "bb"，"bc" -> "b"

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> str:
        final_len = 0
        final_res = ''

        if s == '':
            return ''

        s_new = '#' + '#'.join(s) + '#'
        for i in range(1, len(s_new)):
            j = 1
            while (i - j >= 0 and i + j < len(s_new) and s_new[i - j] == s_new[i + j]):
                j += 1

            j -= 1
            len_new = (i + j) - (i - j) + 1

            if len_new > final_len:
                final_len = len_new
                final_res = s_new[i - j: i + j + 1]
                # print(i + j + 1, ',', i - j)
                # print(final_res)

        return final_res.replace('#', '')
```