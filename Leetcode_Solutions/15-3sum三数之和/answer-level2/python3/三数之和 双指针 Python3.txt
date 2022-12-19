### 解题思路
执行用时 :1072 ms, 在所有 Python3 提交中击败了53.83%的用户
内存消耗 :15.5 MB, 在所有 Python3 提交中击败了98.91%的用户

一：指针的移动
假设从左向右取的三个数分别是a, b, c
因为数组已经经过从小到大的排序，因此指针向左移动三者的和减小，向右移动三者的和增加
因此双指针的移动有三种情况：
1. 情况1：a+b+c=0时，左指针向右移动的同时右指针向左移动
2. 情况2：a+b+c>0时，右指针向左移动
3. 情况3：a+b+c<0时，左指针向右移动
二：优化
两个优化的思想：
1. 优化1：因为数组已经经过从小到大的排序，所以如果a>0，和后续数相加不可能=0，直接break
2. 优化2：如果几个连续的数字相连，为了避免重复计算，将指针移动到最后一个重复的数字上
   注意：这个优化a、b、c元素都要考虑到（分别对应下面注释中：优化2-1、优化2-2、优化2-3）
   所以每次的指针移动都是：
       1. 如果有重复元素，先移动到最后一个重复元素上
       1. 然后根据上述三种情况移动指针

### 代码

```python3
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        # 判例
        if n < 3:
            return []
        nums.sort()
        seen = set()

        for i in range(0, n-2):
            # 优化1
            if nums[i] > 0:
                break
            # 优化2-1
            if i > 0 and nums[i] == nums[i-1]:
                continue

            p = i+1
            q = n-1
            while q-p > 0:
                total = nums[i] + nums[p] + nums[q]
                # 情况1
                if total == 0:
                    seen.add((nums[i], nums[p], nums[q]))
                    # 优化2-2
                    while p < q and nums[p] == nums[p+1]:
                        p += 1
                    # 优化2-3
                    while p < q and nums[q] == nums[q-1]:
                        q -= 1
                    p += 1
                    q -= 1
                # 情况2
                elif total > 0:
                    # 优化2-3
                    while p < q and nums[q] == nums[q-1]:
                        q -= 1
                    q -= 1
                # 情况3
                else:
                    # 优化2-2
                    while p < q and nums[p] == nums[p+1]:
                        p += 1
                    p += 1

        return list(seen)
        
```