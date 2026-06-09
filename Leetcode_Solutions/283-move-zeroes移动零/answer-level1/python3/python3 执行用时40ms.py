### 解题思路
![批注 2020-04-01 201036.png](https://pic.leetcode-cn.com/41d430a146059bd180c772eac02c77bf18f81b39dd1b32ff6451b77f8095f7f7-%E6%89%B9%E6%B3%A8%202020-04-01%20201036.png)

先计算数组中为0的个数count，然后来个for 循环，判断数组中的元素是否为0，若为0，count减一。此时再加个子循环，用来应对多个0出现在一起的情况，子循环最大次数为count。

### 代码

```python3
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        count=nums.count(0)
        for i,ele in enumerate(nums):
            if ele==0:
                nums.pop(i)
                nums.append(0)
                count-=1
                for j in range(count):
                    if nums[i]==0:
                        nums.pop(i)
                        nums.append(0)
                        count-=1
                    else:
                        break
          
                


```