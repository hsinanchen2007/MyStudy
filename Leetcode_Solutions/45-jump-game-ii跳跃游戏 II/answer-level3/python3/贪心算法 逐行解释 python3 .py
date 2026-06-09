# 题解
使用最少的步数到达最后一个位置，则第$i$步位置为第$i-1$步前的点中所能达到的最远位置。
## 贪心算法
 1. 定义步数$step=0$，能达到的最远位置$max\_bound=0$，和上一步到达的边界$end=0$。
 2. 遍历数组，遍历范围$[0,n-1)$：
 	* 所能达到的最远位置$max\_bound=max(max\_bound,nums[i]+i)$，表示上一最远位置和当前索引$i$和索引$i$上的步数之和中的较大者。
 	* 如果索引$i$到达了上一步的边界$end$，即$i==end$，则：
 		+ 更新边界$end$，令$end$等于新的最远边界$max\_bound$，即$end=max_bound$
 		+ 令步数$step$加一
 4. 返回step
 **注意！**数组遍历范围为$[0,n-1)$，因为当$i==0$时，$step$已经加一,所以若最后一个元素也遍历的话，当$end$恰好为$n-1$，步数会多1。


### 复杂度分析
 - 时间复杂度：$O\left(n\right)$
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def jump(self, nums: List[int]) -> int:
        step=0
        end=0
        max_bound=0
        for i in range(len(nums)-1):
            max_bound=max(max_bound,nums[i]+i)
            if(i==end):
                step+=1
                end=max_bound
        return step
```