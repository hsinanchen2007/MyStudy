![image.png](https://pic.leetcode-cn.com/77f89a158bcc329e26cef23706f2665c42983d2374462ff55bd07a8f3322b8c4-image.png)


```
'''
滑动窗口维护窗口中元素的和
'''

from typing import List
class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        target = threshold * k

        total = sum(arr[:k])
        start, end, ans = 0, k-1, 0

        while True:
            if total >= target:
                ans += 1

            if end == len(arr) - 1:
                break

            start, end = start + 1, end + 1
            total -= arr[start-1]
            total += arr[end]

        return ans
```
