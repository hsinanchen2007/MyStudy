## 思路一：暴力
### 代码
时间复杂度：O(n^2)
空间复杂度：O(1)
```c++
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {                
        int size = nums.size();        
        int minLen = INT_MAX;
        for (int i = 0; i < size; ++i) {            
            int sum = 0;
            for (int j = i; j < size; ++j) {
                sum += nums[j];
                if (sum >= s) {
                    minLen = min(minLen, j - i + 1);
                    break;
                }
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};
```

## 思路二：双指针（最优解）
### 代码
时间复杂度：O(n)
空间复杂度：O(1)
```c++
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {                
        int size = nums.size();        
        int minLen = INT_MAX;
        int left = 0, sum = 0;
        for (int i = 0; i < size; ++i) {                                    
            sum += nums[i];
            while (sum >= s) {
                minLen = min(minLen, i - left + 1);
                sum -= nums[left++];                
            }            
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};
```
