### 解题思路
最初采用sorted方法，但是考虑到时间复杂度较高，进而采用桶排序方式
木桶长度为所有高度的范围，初始值为0， 更新木桶数据为列表中对应高度的频次，
再依次输出木桶元素(输出元素一定是按照非递减顺序)，与原列表比较即可确定最小调换人数

### 代码

```python
class Solution(object):
    def heightChecker(self, heights):
        #桶排序 不选择排序是因为时间复杂度高
        bucket = [0]*101 #身高范围1-100
        for h in heights:
            bucket[h] += 1
        count = 0
        j = 0
        max_height = max(heights)
        for i in range(1,max_height+1):
            while bucket[i] != 0 and j < len(heights):
                if i != heights[j]:
                    count += 1
                bucket[i] -=1
                j += 1   
        return count
```