### 解题思路
当后面的和前面的数相等时，将后面的数放到index所指向的位置。然后更新index指向下一个位置。
### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums){
        // // slow solution
        // if(nums.empty())return 0;
        // int history=nums[0];
        // auto i=nums.begin();
        // i++;
        // while(i<nums.end()){
        //     if(*i==history){
        //         nums.erase(i);
        //         continue;
        //     }
        //     history=*i;
        //     i++;
        // }
        if(nums.empty())return 0;
        auto index=nums.begin();
        int history=*index;
        for(auto &i : nums){
            if(index == nums.begin()){
                index++;
                continue;
            }
            if(i != history){
                *index=i;
                index++;
                history=i;
            }
        }
        nums.erase(index,nums.end());
        return nums.size();
    }
};
```