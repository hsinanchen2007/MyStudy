### 解题思路
这道题使用两个指针old_idx与new_idx。
old_idx表示对于老的nums进行遍历。
new_idx表示对于新的nums进行创建。
一旦出现nums[new_idx] != nums[old_idx]
说明出现了新的元素，需要插入到new_array而，这部分已经被遍历过了，因此被覆盖也没有关系
否则，old_idx进行继续的遍历。
这样可以保证old_idx >= new_idx


### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        int old_idx = 1, new_idx = 0, len = nums.size();
        while(old_idx < nums.size()){
            int target = nums[new_idx];
            if(target == nums[old_idx]){
                ++old_idx;
            }else{
                ++new_idx;
                nums[new_idx] = nums[old_idx];
            }
        }
        return new_idx+1;
    }
};
```

### 结果
执行用时 : 16 ms , 在所有 C++ 提交中击败了 77.39% 的用户 
内存消耗 : 7.4 MB , 在所有 C++ 提交中击败了 100.00% 的用户