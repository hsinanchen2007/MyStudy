### 解题思路
利用递归不断找能到达的最左边的点，能走到起点就能跳跃，找不到跳跃点就不行

### 代码

```python3
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        if len(nums)==1:
            return True
        good_point=len(nums)-1
        if_change=0#判断遍历数组的过程中是否找到good_point，没找到就不能递归
        def pro(good_point):
            i=good_point-1
            j=1
            if_change=0
            #从右向左遍历数组

            while i>=0:
                #找到
                if nums[i]>=j:
                    good_point=min(good_point,i)
                    if_change=1
                i=i-1
                j=j+1
                if good_point==0:
                    return True
                if if_change==1:
                    return pro(good_point)
            return False

        return pro(good_point)
```