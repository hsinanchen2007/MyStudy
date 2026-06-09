先求取nums中奇数个数的前缀和$arr$，即$arr[i]$表示$nums$数组中前$i$个数有多少个奇数。
则对于每一个子数组$nums[i...j]$，其中的奇数个数可以采用$arr[j]-arr[i-1]$求得。
则问题转换成有多少个数对$(i,j)$，其中$arr[j]-arr[i] = k$，这就是我们喜闻乐见的$two\ sum$问题啦，用$hash$表即可$O(n)$解决

```
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> arr;
        arr.push_back(0);
        for(auto x:nums) arr.push_back(arr.back() + (x&1));
        
        unordered_map<int,int> h;
        int ans = 0;
        
        for(auto x:arr) {
            ans += h[x-k];
            h[x] ++;
        }
        return ans;
    }
};
```