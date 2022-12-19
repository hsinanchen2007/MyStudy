### 解题思路
此处撰写解题思路
暴力法方便快捷，直接列出所有的顺次数即可！
### 代码

```cpp
class Solution {
    vector<int>nums={12,23,34,45,56,67,78,89,123,234,345,456,567,678,789,1234,2345,3456,4567,5678,6789,12345,23456,34567,45678,56789,123456,234567,345678,456789,1234567,2345678,3456789,12345678,23456789,123456789};
public:
    
    vector<int> sequentialDigits(int low, int high) {
        int i=0;
        vector<int>ans;
        int n=nums.size();
        for(i=0;i<n;i++){
            if(nums[i]<=high&&nums[i]>=low)ans.push_back(nums[i]);
            if(nums[i]>high)break;
        }
        return ans;
    }
};
```