![image.png](https://pic.leetcode-cn.com/6351c3eefbc7a5976eccfdee5c5b7fb537c97ecf6e96d3378c6da3f24b08e4f9-image.png)

### **双指针解法**的解题思路
1、双指针解法应该都能想到，为什么while那一行 j<lenth+1,是因为当第一轮循环，j=lenth后会跳出while循环，此时我的i还没+1继续判断呢，不能退出循环，所以要j<lenth+1，才能保证进入else：i+ =1  j=i+1的循环里 
2、你品，你仔细品。

### 代码
```
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        ##先排除没有重复元素的情况
        if len(set(nums))==len(nums):
            return False
        
        i,j,lenth = 0,1,len(nums)
        while j<lenth+1:
            if j<lenth:
                # print(i,j)
                if nums[i]==nums[j] and abs(j-i)<=k:
                    return True
                else:
                    j+=1
            else:
                i+=1
                j=i+1
        
        return False
```
