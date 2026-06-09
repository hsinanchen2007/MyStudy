### 解题思路
使用zip函数，着重解释zip(*strs)
a = [1,2,3]
b = [4,5,6]
zip(a,b)     # 打包为元组的列表
[(1, 4), (2, 5), (3, 6)]
“*”则是将strs中的所有元素作为参数传进zip中
### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ''
        s = ''
        for i in zip(*strs):
            if len(set(i)) == 1:
                s += i[0]
            else:
                break
        return s

```