**1.暴力解法，两层循环（超出时间限制）**

连续子数组 ： 考虑前缀和
sum[0] = 0
sum[k] = nums[0] + nums[1] + ... + nums[k - 1]

需要找到含有相同数量的0和1的最长连续子数组 ：
sum[ i ] - sum [ j ] = nums[ j ] + nums[ j + 1 ] + ... + nums[ i - 1 ] = k
也即是对应于数组 nums[ ] 中 [ j , i - 1 ] 一段，一共有 k 个 1
所以： 如果 2 * k == i - 1 - j + 1 ( nums[ j , i - 1 ] 一段元素的个数 ) 
即说明有相同数量的0和1，每次记录最大值（数据大，会超时）

```cpp
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        int sum[nums.size() + 1] = {0};
        for(int i = 1;i <= nums.size();i ++)
            sum[i] += sum[i - 1] + nums[i - 1];
        int res = 0;
        for(int i = 1;i <= nums.size();i ++)
           for(int j = 0;j < i;j ++){
               if(2 * (sum[i] - sum[j]) == i - j)
                  res = max(res,i - j);
           }
        return res;
    }
};
```

**2. hash 表**
同题 560：和为k的连续子数组
记录最长的和为0的连续子数组的长度 （当nums[p] == 0 时，看作 nums[p] = -1）
当0 和 1数量相同时，子数组的和为 0  

```cpp
class Solution {
public:
    // 找最长的连续子数组使得其元素的和为0，nums[i] = 0 的元素 i 视为 nums[i] = -1
    // sum[i] = nums[0] + .... + nums[i - 1]
    int findMaxLength(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        int res = 0,sum = 0;
        unordered_map<int,int> hash;  //key : sum[i] , value : i 记录下标
        hash[0] = 0;
        for(int i = 1;i <= nums.size();i ++){
            sum += nums[i - 1] ? 1 : -1;
            if(hash.count(sum)) 
               res = max(res,i - hash[sum]);
            else 
                hash[sum] = i; //要记录最小的i，使res最大，已经有hash[sum]，就不需要更新
        }
        return res;
    }
};
```