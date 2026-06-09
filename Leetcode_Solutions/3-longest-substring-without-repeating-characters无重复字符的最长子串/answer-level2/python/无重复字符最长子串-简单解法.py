### 解题思路
遍历字符串的每一个字符i，判断是否有重复字符，若有则找出重复字符位置str.find()，更新当前无重复字符串，再依次往右排查，并比较无重复字符串长度，最后返回最长长度num。
复杂度为O(n),n为字符串s的长度。
（执行用时32ms,内存消耗11.9MB）

### 代码

```python
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
        else:
            num = 0
            curr_num = 0
            curr = ""
            for i in s: 
                if i not in curr:
                    curr += i
                    curr_num += 1
                    if curr_num > num:
                        num = curr_num
                else:
                    curr = curr[(curr.find(i)+1):] + i
                    curr_num = len(curr)
            return num



```