### 解题思路
二分法：
![...5%A4%8D%E6%95%B0.MP4](c044a07f-3090-4acf-a438-b8f212e15c5e)

快慢指针：
![image.png](https://pic.leetcode-cn.com/1e530fbf0d8ab6be38bace38671ba66d81bad43fbcebe706042d1c519d455304-image.png)

### 代码

```python3
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        #二分法
        left = 1
        right = len(nums)-1

        while left < right:
            # print(left)
            mid = (left + right) // 2
            count = 0
            for num in nums:
                if num <=mid:
                    count +=1
            if count > mid:
                right = mid
            else:
                left = mid+1
        return left
        #快慢指针
        slow = 0
        fast = 0
        while (1):
            slow = nums[slow]
            fast = nums[nums[fast]]
            if slow == fast:
                break
        find = 0
        while (1):
            find = nums[find]
            slow = nums[slow]
            if (find == slow):
                return find
``` 