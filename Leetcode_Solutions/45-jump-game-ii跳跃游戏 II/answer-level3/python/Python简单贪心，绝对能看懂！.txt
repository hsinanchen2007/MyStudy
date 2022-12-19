### 解题思路

![daxc获.PNG](https://pic.leetcode-cn.com/ad835bcff41994dc3bb7e1c2dfbfc6e9f2df2595e642bc7b07b0c59e28f73c18-daxc%E8%8E%B7.PNG)

贪心算法。行数比较长，不过便于理解。
单次遍历，在已知可以到达最后一格的情况下。找出每一次跳跃所有情况下的能够到达的最远距离，这就是下一次跳跃的起点


### 代码

```python3
class Solution:
    def jump(self, nums: List[int]) -> int:
        inde = 0
        n=0
        i=0
        
        
        if len(nums)==1 or not nums:
            return 0 
        while True:
            ax =nums[i]
            if nums[i]+i>=len(nums)-1:
                    
                 return n+1
            for (j,k) in enumerate(range(i,nums[i]+i+1)):
               

                if nums[k]+j>ax:
                    ax =nums[k]+j
                    inde =j
                    
            
            if inde==0:
                inde =nums[i]
            i +=inde
            n +=1
            
            if i>=len(nums)-1:
                
                return n
            inde = 0
            
            
```