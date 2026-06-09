# 题解
借助哈希表保存累加和$sum$及出现的次数。若累加和$sum-k$在哈希表中存在，则说明存在连续序列使得和为$k$。则之前的累加和中，$sum-k$出现的次数即为有多少种子序列使得累加和为$sum-k$。

## 哈希
 1. 初始化哈希表$hash=\{0:1\}$，表示累加和为$0$，出现了$1$次。初始化累加和$sum=0$。初始化结果$count=0$。
 2. 遍历数组：
  	+ 更新累加和$sum+=nums[i]$
  	+ 若$sum-k$存在于$hash$中，说明存在连续序列使得和为$k$。则令$count+=hash[sum-k]$，表示$sum-k$出现几次，就存在几种子序列使得和为$k$。
  	+ 若$sum$存在于$hash$中，将其出现次数加一。若不存在，将其加入$hash$
 
 3. 返回$count$

### 复杂度分析
 - 时间复杂度：$O\left(n\right)$
 - 空间复杂度：$O(n)$

### Python

```python
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        hash={0:1}
        sum=0
        count=0
        for i in range(len(nums)):
            sum+=nums[i]
            if((sum-k) in hash):
                count+=hash[sum-k]
            if(sum in hash):
                hash[sum]+=1
            else:
                hash[sum]=1
        return count

```