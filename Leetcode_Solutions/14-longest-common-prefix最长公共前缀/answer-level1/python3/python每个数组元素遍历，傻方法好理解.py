### 解题思路
先是判断输入是否为空数组，若是返回“”，若不是，用min(strs,key=len)找到数组中长度最小的元素，若最小元素为“”，则返回“”，否则对每个数组元素中第j个字符(j从0到最短元素长度进行遍历)做比较，若strs[i][j]=strs[i+1][j],则表示第i个元素的第j个字符与i+1个元素的第j个字符一直，则判断标志位加1，对每个元素的第j个元素遍历结束后，判断标志位，若满足num=len(strs)-1,则将第[j]个字符加到加过数组中，依次遍历，直到有第j个元素的标志位不满足条件为止，输出结果数组。

### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        x=""
        num=0
        if len(strs) == 0:
            return ""
        else:
            s1=min(strs,key=len)
            if s1=="":
                return ""
            else:    
                for j in range(len(s1)):
                    for i in range(len(strs)-1):
                        if strs[i][j]==strs[i+1][j]:
                            num+=1
                    if num==len(strs)-1:
                        x+=strs[0][j]
                        num=0
                    else:
                        return x
                        num=0
                return x
```