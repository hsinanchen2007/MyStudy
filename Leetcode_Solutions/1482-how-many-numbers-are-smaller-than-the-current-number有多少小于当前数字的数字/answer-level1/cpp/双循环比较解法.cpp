### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans;
        for(int i = 0; i< size; i++) {
            int count = 0;
            for(int j = 0; j < size; j++) {
                if(nums[j] < nums[i]) {
                    count+=1;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};
```