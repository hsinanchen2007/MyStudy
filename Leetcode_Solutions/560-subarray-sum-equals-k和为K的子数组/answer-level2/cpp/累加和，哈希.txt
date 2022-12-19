- ### 累加和
`sum[i]`代表从`0`到`i`的和，`sum[j]-sum[i]`即`i-j`的和，把所有的前缀和放到一个数组中，最后两两相减，凡是符合差值等于`k`的就记录下来。
```

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int>res(nums.size()+1,0);
        int sum=0,count=0;
        for(int i=1;i<=nums.size();i++){
            sum+=nums[i-1];
            res[i]=sum;
        }
        for(int i=0;i<res.size()-1;i++){
            for(int j=i+1;j<res.size();j++){
                if((res[j]-res[i])==k){
                    count++;
                }
            }
        }
        return count;
    }
};
```
- ### 哈希表
由法一知，`sum[j]-sum[i]=k`时`count`次数加一，那么倒过来想一下为什么不能一边记录`sum[i]`一边找`sum[j]-sum[i]=k`。当然也是可以做到的。方法就是
- 用字典记录下前缀和以及其出现的次数，`key`为`sum[i]`,`value`为`sum[i]`出现次数。
- 每次到`sum[j]`时，先看一下字典中有没有`sum[j]-k`的键，如果有，(假设`sum[i]=sum[j]-k`)则说明从`i`到`j`之间的和必是`k`，那么这不正是我们需要的么(hahahhahahaha)，如果没有就往字典里`key`值呗
```
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res=0,sum=0;
        unordered_map<int, int> dict;
        dict[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(dict[sum-k]){
                dict[sum-k];
                res+=dict[sum-k];
            }
            dict[sum]++;
        }
        return res;
    }
};
```



