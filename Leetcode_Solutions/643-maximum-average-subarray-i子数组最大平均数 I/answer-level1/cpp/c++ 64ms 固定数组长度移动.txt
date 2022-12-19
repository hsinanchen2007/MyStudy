### 解题思路
![5288ccf540b5599d734f398ac21188f.png](https://pic.leetcode-cn.com/894e42324f11c68cedd666c72adbcf5d45ee62fdd9cda70346ccc9c017e74f72-5288ccf540b5599d734f398ac21188f.png)


### 代码

```cpp
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int len = nums.size();
        double sum = 0;
        for(int i = 0 ; i < k ; ++i)
            sum += nums[i];
        double maxn = sum;
        for(int i = k - 1; i < len - 1 ; ++i){
            sum = sum - nums[i + 1 - k] + nums[i + 1];
            maxn = max(sum, maxn);
        }
        return maxn * 1.0 / k;
    }
};
```