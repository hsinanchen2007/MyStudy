### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        vector<int> temp = nums;
        sort(nums.begin(),nums.end());
        int size = nums.size();
        int maxL = nums[size-1];

        for(int i = 0;i<size-1;i++){
            if(2*nums[i] > maxL){
                return -1;
            }
        } 
        int i = 0;
        for(;i<temp.size();i++){
            if(temp[i] == maxL) break;
        }
        return i;
    }
};
```