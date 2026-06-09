### 解题思路
判断s是否为t的子序列
两种方法：
1.双指针
两个指针分别指向s和t，对t依次探索，如果t当前探索元素与s当前指向元素相同，s指针再往后移
2.遍历s，判断当前探索元素是否在t内，如果在，把t前面元素全部切割掉
时间复杂度都是m+n


### 代码

```python
class Solution(object):
    def isSubSequence(str1, str2):
        m = len(str1)
        n = len(str2)
        j = 0   # Index of str1
        i = 0   # Index of str2
        while j < m and i < n:
            if str1[j] == str2[i]:  
                j = j + 1
            i = i + 1
            
        return j == m

    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        for i in s:
            if i in t:
                t = t[t.index(i)+1:]
            else:
                return False
        return True

```