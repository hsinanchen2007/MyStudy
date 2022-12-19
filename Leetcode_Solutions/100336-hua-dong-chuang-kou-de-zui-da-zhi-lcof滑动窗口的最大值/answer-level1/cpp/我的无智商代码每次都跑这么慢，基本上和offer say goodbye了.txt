### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int max1(vector<int>& nums,int k,int start)
    {
        int Max=nums[start];
        for(int i=start;i<start+k;i++)
            Max=max(Max,nums[i]);
        return Max;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> arr;
        if(nums.empty())return arr;
        for(int i=0;i<=nums.size()-k;i++)
            arr.push_back(max1(nums,k,i));
        return arr;
    }
};
```