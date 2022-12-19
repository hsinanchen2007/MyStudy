### 解题思路
1、先排序；
2、记录一个最小差，默认为前两个项的差；
3、遍历一遍，同时把元素对保存到容器中；
4、遇到更小的差时，更新最小差，清空容器。

### 代码

```python3
class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()

        r = []
        n = arr[1] - arr[0]
        
        for i in range(len(arr)-1):
            if arr[i+1] - arr[i] == n:
                r.append([arr[i], arr[i+1]])
            elif arr[i+1] - arr[i] < n:
                r = []
                n = arr[i+1] - arr[i]
                r.append([arr[i], arr[i+1]])
                
        return r
```