### 解题思路
1、定义两个指针，当作滑动窗口
2、在右边滑动窗不出界的情况下就一直循环，得到最后结果

### 代码

```python3
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        ##双指针的方式
        res = []
        L = 0
        R = L+k
        if len(nums)>0:
            while R<len(nums)+1:
                maxValue = max(nums[L:R])
                res.append(maxValue)
                L+=1
                R+=1
            return res
        else:
            return nums


```
![image.png](https://pic.leetcode-cn.com/98ff9c6c18c92878e04eafe78339cbfeef6be22f79ac25cd86e9b950aa753f56-image.png)
