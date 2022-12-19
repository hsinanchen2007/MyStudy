### 解题思路
回文串的回文中心两侧互为镜像，我们可以利用此特点来寻找回文串。思路是以回文中心为起点，向两侧扩展，找到满足回文条件的最长扩展串，即为最长回文子串。长度为n的字符串有2n-1个回文中心，因为回文子串长度可能为奇数或偶数。长度为奇数时初始中心长度为1，偶数时为2。所以我们需要寻找奇/偶回文子串的最大长度。
时间复杂度：O(n^2)，由于围绕中心来扩展回文会耗去 O(n) 的时间，所以总的复杂度为 O(n^2)。

空间复杂度：O(1)。

作者：LeetCode
链接：https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zui-chang-hui-wen-zi-chuan-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> str:
        begin, end = 0, 0
        for i in range(len(s)):
            len1 = self.expandAroundCenter(s, i, i)
            len2 = self.expandAroundCenter(s, i, i+1)
            length = max(len1, len2)
            if length > (end - begin + 1):
                begin = int(i - int((length-1)/2))
                end = int(i + length/2)
        return s[begin:end+1]
    def expandAroundCenter(self, s, left, right):
        while(left>=0 and right<=len(s)-1 and s[left]==s[right]):
            left -= 1
            right += 1
        return right - left - 1

```