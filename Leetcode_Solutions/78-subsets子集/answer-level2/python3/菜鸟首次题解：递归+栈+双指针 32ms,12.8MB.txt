### 解题思路
    小生对刚学数据机构，对这种题一直都是云里雾里，感觉本题可以用递归做，但是不知如何下手，所以我思索了一下：如果用递归解题，那么递归的核心是什么，也就是每次递归对结果的影响是什么。

    既然是求子集，我们可以通过子集的不同长度进行递归(所求子集的长度范围是 0 到 len(nums)) 

    接下来的问题就是 针对给定的数组，如果求某特定长度的子集

    我想到了用栈来解决这个问题

    = = 思路表达不清了 = = 晚会儿回来再更 = =
    




### 代码

```python3
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = [[]]
        length = len(nums)
        def recursion(now_len):
            if now_len == length:
                res.append(nums)
                return True
            cur_len = 1
            stack = []
            pointer1,pointer2 = 0,0
            while len(nums) - pointer1 >= now_len:
                if cur_len < now_len:
                    if pointer2 == len(nums) - 1:
                        stack.pop(0)
                        if stack == []:
                            pointer1 += 1
                            pointer2 = pointer1
                        else:
                            pointer2 = stack.pop(0) + 1
                            stack.insert(0,pointer2)
                    else:
                        pointer2 += 1
                        stack.insert(0,pointer2)
                    cur_len = len(stack) + 1
                elif cur_len == now_len:
                    Res = [nums[pointer1]]
                    for i in stack:
                        Res.append(nums[i])
                    res.append(Res)
                    if stack == []:
                        pointer1 += 1
                        pointer2 = pointer1
                        cur_len = 1
                    else:
                        pointer2 = stack.pop(0) + 1
                        if pointer2 > len(nums) - 1:
                            if stack == []:
                                pointer1 += 1
                                pointer2 = pointer1
                                cur_len = 1
                            else:
                                pointer2 = stack.pop(0) + 1
                                stack.insert(0,pointer2)
                                cur_len = len(stack) + 1
                        else:
                            stack.insert(0,pointer2)
            recursion(now_len + 1)
        recursion(1)
        return res

                
            
```