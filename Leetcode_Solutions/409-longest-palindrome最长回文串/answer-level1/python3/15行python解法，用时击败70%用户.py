### 解题思路
字符串转列表，调用排序函数排序。
字符两两判断是否相等，相等则序号跳2，不等则序号跳1。
字符串的长度不用分奇偶考虑。

### 代码

```python
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        str_list=[]
        sum=1
        for i in range(len(s)):
            str_list.append(s[i])
        str_list.sort()
        i=0
        while(i<len(s)-1):
            if str_list[i]==str_list[i+1]:
                sum+=2
                i+=2
            else:
                i+=1
        if sum>len(s):
            sum=len(s)
        return sum
```