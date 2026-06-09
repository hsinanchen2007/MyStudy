### 解题思路
1.从第二个元素开始遍历
2.如果当前元素比前一个元素大则当前长度+1，否则当前长度为1.
3.取历次长度的最大值。

### 代码

```cpp
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.empty()) 
            return 0;
        int maxLen = 1;
        int currentLen = 1;//从第二个元素开始遍历
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > nums[i-1])// 如果大于上一元素 f(i) = f(i-1) + 1
                currentLen += 1;
            else
                currentLen = 1;
            maxLen = max(currentLen,maxLen);
        
        }
        return maxLen;
    }
};
```