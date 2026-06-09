### 解题思路
先排序，再逐一遍历数组元素。

### 代码
```
class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        if len(arr)<3:
            return [arr]
        mindiff=arr[1]-arr[0]
        res=[[arr[0],arr[1]]]
        for i in range(2,len(arr)):
            curdiff=arr[i]-arr[i-1]
            if curdiff<mindiff:
                res=[[arr[i-1],arr[i]]]
                mindiff=curdiff
            elif curdiff==mindiff:
                res.append([arr[i-1],arr[i]])
        return res
```



![image.png](https://pic.leetcode-cn.com/d09358b6f91969c673c249ad6bf9ce95926eb821387cce3265d3b42e08edf939-image.png)
