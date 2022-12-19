### 解题思路
此处撰写解题思路
排序后与后一个数进行比较
### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int i=0;
        sort(nums.begin(),nums.end());
        for(i;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                break;                
            }
        }
        return nums[i];
    }
};
```