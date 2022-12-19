# $O(N^2)$
## Brute-force
### Nested *for* loop
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        size_t n = nums.size();
        int max = nums[0];
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum > max) {
                    max = sum;
                }
            }
        }
        return max;
    }
};
```
### Complexity
- Time: $O(N^2)$
- Space: $O(1)$

# $O(N)$
## Divide and Conquer
### TODO: *Too complicated...*
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

    }
};
```



## DP & Greedy
### DP function: $f(k) = \max(nums[k], f(k +1)+nums[k])$
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        size_t n = nums.size();
        int sum = 0;
        int max = nums[0];
        
        for (int i = 0; i < n; i++) {
            sum = std::max(nums[i], nums[i] + sum);
            max = std::max(max, sum);
        }
        return max;
    }
};
```
### Complextity
- Time: $O(N)$
- Space: $O(1)$