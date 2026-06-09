### 解题思路
应该是动态规划？从后往前遍历，并维护一个大小为3的list。
这个list存的是当前值往后三个位置所能得到的最大值，可以论证再往后的位置得到的值一定比这个list中的小

### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        l = len(nums)
        temp = [0]*3
        for i in range(l-1, -1, -1):
            index = i%3
            temp[index] = max(temp[(index+2)%3],temp[index]) + nums[i]
        return max(temp)

```