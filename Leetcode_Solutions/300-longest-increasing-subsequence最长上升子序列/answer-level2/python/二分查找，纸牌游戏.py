### 解题思路
二分查找，纸牌游戏
借鉴思路：
以前的Windows XP就有这种纸牌游戏，每张牌只能放在比它大的牌上面，如果没有就增加一堆牌。
每堆牌的牌顶组成有序数组，可利用二分查找
答案就是牌堆的数量

### 代码

```python3
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        # 二分查找，纸牌游戏：每张牌只能放在比它大的牌上面，如果没有就增加一堆牌
        # 每堆牌的牌顶组成有序数组，可利用二分查找
        # 答案就是牌堆的数量

        top = []
        for poker in nums:
            if not top:
                top.append(poker)
                continue

            left, right = 0, len(top)-1
            while left < right:
                mid = (left + right) >> 1
                # 如果poker不小于mid，往右边找[mid+1, right]
                if poker > top[mid]:
                    left = mid + 1
                else:
                    right = mid

            # 如果没找到合适的牌堆，自己新建一堆
            if poker > top[left]:
                top.append(poker)
            else:
                 # 如果找到合适牌堆，这张牌放在最上面
                top[left] = poker

        return len(top)

```