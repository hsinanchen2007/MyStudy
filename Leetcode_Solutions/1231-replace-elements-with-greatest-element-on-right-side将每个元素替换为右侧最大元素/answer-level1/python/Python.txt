

### 代码

```python3
class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        '''
        将元素替换为右侧最大的元素
        每次找到右侧最大元素
        '''
        maxnum = arr[0]
        for i in range(len(arr)):
            if i == len(arr)-1:
                arr[i] = -1
                break
            # 得到右边的最大值
            # 只有当当前元素为最大值时才需要更新最大值
            if arr[i] == maxnum:
                maxnum = max(arr[i+1:])
            arr[i] = maxnum
        return arr
```