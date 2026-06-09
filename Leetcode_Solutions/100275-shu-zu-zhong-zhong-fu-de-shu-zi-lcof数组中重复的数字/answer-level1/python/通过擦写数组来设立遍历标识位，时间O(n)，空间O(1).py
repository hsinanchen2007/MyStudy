### 解题思路
从左向右遍历数组，按照哈希的方式对已经遍历过的位置置为-1，然后再从那个位置继续相同操作，直到不能继续置位为止。此时假如当前数位i，则必定停留在第i位上。举个例子：
2,3,1,0,2,5,3
第一次遍历直到，数组变成-1,-1,-1,-1,2,5,3，最后一次要置位的是0，停留在了第0位上。

然后继续遍历，遇到-1的就跳过（已经置位了）。遇到不是-1的，继续以上置位操作，当遇到某个数已经被置位，则反映出数组有循环元素。比如
-1,-1,-1,-1,2,5,3中，接下来该遍历2，但是第3个位置已经被置位了。

这样我们只需要开辟额外1个空间进行数组擦鞋，空间复杂度O(1).
从左到右遍历。在遍历的过程中需要置位，但总共也只有n个位置需要置位。所以时间复杂度O(n).

### 代码

```python3
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        # check input
        # for num in nums:
        #     assert num > -1
        # print("Check passed.")   
    
        res = None 
        for i, num in enumerate(nums):
            while num != -1:
                tmp = nums[num]
                if nums[num] == -1:
                    res = num 
                    break
                else:
                    nums[num] = -1
                    if tmp != i:
                        num = tmp
                    else:
                        break
            if res is not None:
                break
        return res
```