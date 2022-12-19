### 解题思路
如标题所示

### 代码

```python
class Solution(object):
    def commonChars(self, A):
        """
        :type A: List[str]
        :rtype: List[str]
        """
        from collections import Counter
        temp=[]
        for word in A:
            temp.append(Counter(word))
        result=[]
        for key,value in temp[0].items():
            # print key,value
            result.append([key,min([x[key]   for x in temp ])])
        final=[]
        for key,value in result:
            if value>0:
                final.extend([key for _ in range(value)])
        return final
```