区别于普通二分法，每次切完之后，要判断剩下的子数组是否还包含两段。如果不包含，就是普通二分法，如果包含，就要仔细分类讨论。
内存消耗有点高。
![image.png](https://pic.leetcode-cn.com/b6e39464ff58dc44c454e9b54603add9eb9a6419bbb0064bce5f160979cc5b22-image.png)


```
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        L = 0
        R = len(nums) - 1
        if nums == []:
            return -1

        if target < nums[L] and target > nums[R]:
            return -1

        while R - L >= 2:
            if nums[L] == target:
                return L
            if nums[R] == target:
                return R
            mid = (L + R) // 2
            if nums[mid] == target:
                return mid

            if nums[L] > nums[R]:   # 说明当前子数组仍包含两段
                if target < nums[R]:    # 则target在旋转后的右分组
                    if nums[mid] > nums[L]:   # 说明切到了左分组
                        L = mid
                    elif nums[mid] < target:
                        L = mid
                    elif nums[mid] > target:
                        R = mid

                elif target > nums[L]:   # 则target在左分组
                    if nums[mid] < nums[R]:    # 说明切到了右分组
                        R= mid
                    elif nums[mid] < target:
                        L = mid
                    elif nums[mid] > target:
                        R = mid
            else:
                if nums[mid] > target:
                    R = mid
                elif nums[mid] < target:
                    L = mid

        if L == R:
            if nums[L] == target:
                return L
            else:
                return -1
        elif R - L == 1:
            if nums[L] == target:
                return L
            elif nums[R] == target:
                return R
            else:
                return -1







```
