### 解法一：数组实现
1. 数组实现，线性时间复杂度

### 解法一代码

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int hash[n + 1];
        int ans;
        memset(hash, 0, sizeof(hash));
        for(int n : nums){
            hash[n] ++;
        }
        for(int i = 0; i <= n; i++){
            if(hash[i] == 0) ans = i;
        }
        return ans;
    }
};
```


### 解法二：哈希表实现
1. 哈希表实现，算法复杂度同解法一

### 解法二代码

```cpp

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans;
        for(int n : nums) mp[n] ++;
        for(int i = 0; i <= nums.size(); i++){
            if(mp[i] == 0){
                ans = i;
                break;
            }
        }
        return ans;
    }
};
```
