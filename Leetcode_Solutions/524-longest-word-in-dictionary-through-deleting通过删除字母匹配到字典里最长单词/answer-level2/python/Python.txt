### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def findLongestWord(self, s, d):
        """
        :type s: str
        :type d: List[str]
        :rtype: str
        """
        def issubstring(a,b):
            len_a=len(a)
            len_b=len(b)
            if len_a<len_b:
                return False
            i=0
            j=0
            while i<len_a and j<len_b:
                if a[i]==b[j]:
                    i=i+1
                    j=j+1
                    if j==len_b:
                        return True
                else:
                    i=i+1
            return False

        def xiaoyu(a,b):
            len_a=len(a)
            len_b=len(b)
            i=0
            j=0
            while i<len_a and j<len_b:
                if a[i]>b[j]:
                    return True
                elif a[i]==b[j]:
                    i=i+1
                    j=j+1
                else:
                    return False
            return False
        max=0
        maxans=""
        for string in d:
            if issubstring(s,string) and len(string)>max:
                maxans=string
                max=len(string)
            elif issubstring(s,string) and len(string)==max and xiaoyu(maxans,string):
                maxans=string
                max=len(string)
            
        return maxans
```