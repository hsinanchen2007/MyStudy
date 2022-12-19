### 解题思路

前缀和 ：sum[ ]数组，大小为 nums.size() + 1 , sum[i] 记录前 i 个数的和

sum[0] = 0

sum[i] = nums[0] + nums[1] + nums[2] + .... + nums[i - 1]

sum[i] - sum[j] = nums[j] + nums[j+1] + ... +nums[i - 1] = k

sum[j] = sum[i] - k

hash表：

`unordered_map<int,int> hash   // key : sum[j]  , value : sum[j]的个数`

对于一个 sum[i] 累加 sum[j] 的个数 (1<=i<=nums.size()+1)

注意：初始化 `hash[0] = 1;` 因为 sum[0] = 0 有1个


### 代码

```cpp
class Solution {
public: 
    //前缀和 + hash
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> hash;  // key : sum[j]  , value : sum[j]的个数
        int res = 0,sum = 0;
        hash[0] = 1;  // sum[0] = 0
        for(int i = 1;i <= nums.size();i ++){
            sum += nums[i];
            if(hash[sum - k])
               res += hash[sum - k];
            hash[sum] ++;
        }
        return res;
    }
};
```