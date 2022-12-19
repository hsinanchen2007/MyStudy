### 思路：

- 先计算每个长度为`k`的子数组的和
- 储存当中间子数组为开始下标为`i`时左子数组的最优开始下标`j`
- 储存当右子数组开始下标为`r`时中间子数组的最优开始下标`m`，此时可同时计算结果
### 代码：
```python []
class Solution:
    def maxSumOfThreeSubarrays(self, nums: [int], k: int) -> [int]:
        n = len(nums)
        l = n - k + 1     
        sums = [0] * l      #储存每个长度为k的子数组的和
        s = sum(nums[:k])
        sums[0] = s
        for i in range(1,l):
            s = s + nums[i+k-1] - nums[i-1]
            sums[i] = s

        #中间子数组为i时左子数组的开始位置
        mid = {i:0 for i in range(k,l)}   #初始化为0
        for i in range(k, l):
            j = mid.get(i-1,0)
            if sums[i-k] > sums[j]: #保证中间数组开始为i时左子数组为最优
                j = i-k
            mid[i] = j  #中间子数组开始为i时左子数组开始为j

        #右子数组开始为i时中间子数组开始位置
        right = {i:k for i in range(2*k,l)} #初始化为k
        res = [0, k, 2 * k]
        for r in range(2 * k, l):
            m = right.get(r-1,k)
            #当右子数组开始下标为r时，此时左子数组与中间子数组的最大和
            if sums[r-k]+sums[mid[r-k]] > sums[m]+sums[mid[m]]:
                m = r - k
            right[r] = m    #右子数组开始下标为r时中间数组开始下标为m
            if sums[r]+sums[m]+sums[mid[m]] > sums[res[0]]+sums[res[1]]+sums[res[2]]:
                res = [mid[m], m, r]
        return res
```
```javascript []
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var maxSumOfThreeSubarrays = function(nums, k) {
    let n = nums.length
    let l = n - k + 1
    let sums = Array(l).fill(0)
    let s = nums.slice(0,k).reduce((x,y) => x+y)
    sums[0] = s
    for (let i=1;i<l;i++){
        s = s + nums[i-1+k] - nums[i-1]
        sums[i] = s
    }
    let j,m
    let mid = new Map()
    for (let i=k-1;i<l;i++){
        mid.set(i,0)
    }
    for (let i=k;i<l;i++){
        j = mid.get(i-1)
        if (sums[i-k] > sums[j]){
            j = i-k
        }
        mid.set(i,j)
    }
    let right = new Map()
    for (let i=2*k-1;i<l;i++){
        right.set(i,k)
    }
    let res = [0,k,2*k]
    for (let r=2*k;r<l;r++){
        m = right.get(r-1)
        if (sums[r-k]+sums[mid.get(r-k)] > sums[m]+sums[mid.get(m)]){
            m = r-k
        }
        right.set(r,m)
        if (sums[r]+sums[m]+sums[mid.get(m)] > sums[res[0]]+sums[res[1]]+sums[res[2]]){
            res = [mid.get(m),m,r]
        }
    }
    return res
};
```
### 复杂度分析：
时间复杂度：O(n)
空间复杂度：O(n)