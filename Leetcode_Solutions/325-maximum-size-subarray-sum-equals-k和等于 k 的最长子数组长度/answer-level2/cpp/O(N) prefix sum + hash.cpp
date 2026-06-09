1. 我们知道如何最终结果为sum(i,j)为从i到j的子序列和，则sum(i,j) = sum(0,j) - sum(0,i-1);
2.按照第一条的规则，假设sum(i,j) = k,则  sum(0,j) = k + sum(0,i-1),因此我们利用hash查找是否存在前N项和的值为sum(0,n) - k,如果找到，则输出结果。
3.代码如下所示：

```c++ []
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int ans = 0;
        map<int,int> prefix;
        
        prefix[0] = 0;
        for(int i = 0;i < n; ++i){
            sum += nums[i];
            if(!prefix.count(sum)){
                prefix[sum] = i + 1;
            }
            if(prefix.count(sum-k)){
                ans = max(ans,i + 1 - prefix[sum-k]);
            }
        }
        
        return ans;
    }
};
```
```python []
class Solution:
    def maxSubArrayLen(self, nums: List[int], k: int) -> int:
        s = 0
        ans = 0
        prefix = {}
        
        prefix[0] = 0
        for i in range(len(nums)):
            s += nums[i]
            if s not in prefix:
                prefix[s] = i+1
            if s-k in prefix:
                ans = max(ans,i+1-prefix[s-k])
                
        return ans
```