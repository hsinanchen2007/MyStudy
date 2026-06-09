### 解题思路
方法一：水平扫描
取一个元素作为基准，与每个元素比较


### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs)==0:
            return ""
        lcp=strs[0]
        for i in range(1,len(strs)):
            while strs[i].find(lcp)!=0:
                lcp=lcp[:-1]
        return lcp
```

### 解题思路
方法二：垂直扫描
分离元素，组成矩阵，挨个比较每个字母

### 代码
```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        lcp=""
        for each in zip(*strs):
            if len(set(each))==1:
                lcp+=each[0]
            else:
                break
        return lcp
```