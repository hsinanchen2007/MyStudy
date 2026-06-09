### 解题思路
python 滑动窗口，固定k大小窗口，后续计算只需已有均值+窗口头尾相减的均值

### 代码

```python
class Solution(object):
    def numOfSubarrays(self, arr, k, threshold):
        """
        :type arr: List[int]
        :type k: int
        :type threshold: int
        :rtype: int
        """
        count = 0
        now_avg = sum(arr[0:k])*1.0/k
        j = 0
        if now_avg>=threshold:
            count = count + 1
        for i in range(k,len(arr)):
            now_avg = now_avg + (arr[i] - arr[j])*1.0/k
            j = j+1
            if now_avg >= threshold:
                count = count+1
        return count
```