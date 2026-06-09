### 动态规划

我最开始的思路是，建立bool类型的`flags`数组，表示能否跳到该节点。在求解`flags[i]`时，向前遍历，如果存在`flags[j]`为True且能从j跳到i，那么`flags[i]`就为True。

```python []
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        flags = [True]
        flag = False
        for i in range(1, len(nums)):
            flag = False
            for j in range(i-1,-1,-1):
                if (flags[j] and nums[j] + j >= i):
                    flag = True
                    flags.append(True)
                    break
            if(not flag):
                flags.append(False)
        return flags[len(flags)-1]
```

事实上，这样做很冗余，我们不需要利用数组来存储是否能跳到某节点。这里有个逻辑，如果能想通，那就简单了:

- **如果跳不到i点，那么一定跳不到i后面的点。**

- **如果可以跳到i点，则说明一定可以跳到i前面的任意一点。**

所以我们只需要一个`flag`即可，表示能否跳到当前节点。任意一个节点跳不到，那么肯定到达不了最后一个节点，直接return False即可。

```python []
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        flag = False
        for i in range(1, len(nums)):
            flag = False
            for j in range(i-1,-1,-1):
                if (nums[j] + j >= i):
                    flag = True
                    break
            if(not flag):
                return False
        return True
```

复杂度分析：

时间复杂度：平均O(n2),最好O(n),最差O(n2)

空间复杂度: O(1)


dp解决这道题ok，但思路不好扩展到`45. 跳跃游戏 II`上。解决45题，最优解是贪心算法。