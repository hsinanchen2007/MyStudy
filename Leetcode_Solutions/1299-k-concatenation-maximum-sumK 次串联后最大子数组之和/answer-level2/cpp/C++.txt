1. 因为题目中的问题有点特殊，无非是求重复K次的字符串的最大连续子串之和.
2. 如果整个数组的和小于0，则k次重复的最大子序列和为```max(subsum(arr1),subsum(arr2))```.
3. 如果整个数组的和大于0, 则这时分为两种情况```subsum(arr1) == subsum(arr2)```,则这时
   ```ans = max(sum,max1)```,否则```ans = max((k*sum),(subsum(arr2) + (k-2)*sum))```.
![61-1.png](https://pic.leetcode-cn.com/ed67b59599277360b8b254fd03d3cf39952374f586fa534c705a2a3487c25a53-61-1.png)

```
class Solution {
public:
    long long maxSubSum(vector<int> & arr){
        long long curr = 0;
        long long ans = 0;
        
        for(int i = 0; i < arr.size(); ++i){
            curr += arr[i];
            ans = max(ans,curr);
            if(curr < 0){
                curr = 0;
            }
        }
        
        return ans;
    }

    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long sum = 0;
        long long max1 = 0;
        long long max2 = 0;
        long long mod = 1000000007;
        vector<int> twice;
        
        for(int i = 0; i < arr.size(); ++i){
            sum += arr[i];
        }
        twice.insert(twice.begin(),arr.begin(),arr.end());
        twice.insert(twice.begin(),arr.begin(),arr.end());
        max1 = maxSubSum(arr);
        max2 = maxSubSum(twice);
        
        if(k == 1){
            return max1;
        }
        
        if(sum < 0){
            return max(max1,max2);
        }else{
            if(max1 == max2){
                return max((k*sum)%mod,max1);
            }else{
                return max((k*sum)%mod,(max2 + (k-2)*sum)%mod);
            }
        }
    }
};
```