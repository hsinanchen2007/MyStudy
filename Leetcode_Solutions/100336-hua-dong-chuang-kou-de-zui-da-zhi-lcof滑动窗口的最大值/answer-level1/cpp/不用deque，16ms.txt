### 解题思路
暴力解法下稍微修改

### 代码

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        int index=-1;
        for(int i=0;i<nums.size();i++){
            int j;
            if(index<i) {
                index=i;
                j=i;
            }
            else {
                j=i-1+k;
            }
            if(i+k>nums.size()) break;
            while(j<i+k){
                if(nums[j]>nums[index]) index=j;
                j++;
            }
            ret.push_back(nums[index]);
        }
        return ret;
    }
};
```