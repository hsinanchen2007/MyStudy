### 解题思路
![228_sumRange.png](https://pic.leetcode-cn.com/de2faff6e10742f08421a00b0a7c63c477751e0c8b918d26ddf35c59f60f72d8-228_sumRange.png)
这道题最大的意义就在于test case: [-2147483648,-2147483647,2147483647]
当心type overflow
所以应该写成nums[i + 1] ==  nums[i] + 1 而不是nums[i + 1] - nums[i] == 1。
道理好像二分法求中点最佳写法是 mid = (left + (right - left))/2 而不是 mid = (left + right)/2。
### 代码

```cpp
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        //[[ ... ] , [ ... ] , [ ... ]]
        int len = nums.size();
        if (!len) return ret;
        int lo {0};        
        for (int i = 0; i < len; ++i){            
            if ((i < len - 1 ) && (nums[i + 1] ==  nums[i] + 1)){                
                ++cnt;
            } 
            else {                
                if (i == lo) ret.push_back(to_string(nums[lo]));
                else  ret.push_back(to_string(nums[lo]) + "->" + to_string(nums[lo] + cnt));
                
                if (i < len - 1) lo = i + 1;                
                cnt = 0;
            }
        }
        return ret;
    }
private:    
    int cnt {0};
    vector<string> ret;
};
```