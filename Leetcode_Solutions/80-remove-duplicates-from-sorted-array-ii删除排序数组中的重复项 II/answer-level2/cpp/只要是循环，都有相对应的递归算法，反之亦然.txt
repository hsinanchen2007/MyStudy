### 解题思路
假设curr指向已经处理好的最后数据位置，count表示curr指向数据的重复个数，next表示下一个要处理的数据位置
就可以很好的把迭代变成递归。



### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2)
            return nums.size();

        return removeDuplicates(0, 1, 1, nums ) + 1;
        /****
        int curr_index = 0;
        int val_count = 1;
        for(int i = 1; i < nums.size(); i++){
           if(nums[i] != nums[curr_index]){
               nums[++curr_index] = nums[i];
               val_count = 1;
           }else if(nums[i] == nums[curr_index] && val_count < 2){
               nums[++curr_index] = nums[i];
               val_count++;
           }
        }

        return curr_index + 1;
        ***/
    }

    //0, 1, 1, nums
    int removeDuplicates(int curr, int count, int next, vector<int>& nums){
        if(next == nums.size())
            return curr;
        if(nums[curr] != nums[next]){
            nums[++curr] = nums[next];
            count = 1;
        }else if(count < 2){
            nums[++curr] = nums[next];
            count++;
        }
        return removeDuplicates(curr, count, next + 1, nums);
    }
};
```