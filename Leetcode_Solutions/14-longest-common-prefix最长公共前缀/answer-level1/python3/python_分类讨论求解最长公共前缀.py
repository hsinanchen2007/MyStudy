### 解题思路
算是最笨的暴力解法了
分类1：列表为空，公共前缀为空
分类2：列表只有一个元素，公共前缀为第一个元素
分类3：列表元素多于2时：假定最长前缀为第一个元素
       遍历之后的元素，遇见不同则截取，元素长度少于公共前缀长度时也截取
      

### 代码

```python
class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if strs==[]:
            return ""
        if len(strs)==1:
            return strs[0]
        mylist=[str(s) for s in strs[0]]
        n=len(mylist)
        for i in range(1,len(strs)):
            for j in range(n):
                if j>=len(strs[i]):
                    n=len(strs[i])
                    break
                if strs[i][j]==mylist[j]:
                    continue
                else:
                    n=j
                    break
            if n==0:
                break
        result=""
        if n>=0:
            for i in mylist[0:n] :
                result=result+str(i)
        return result
```