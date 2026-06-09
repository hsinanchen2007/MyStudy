### 解题思路
避免对重复数据的多次删除

### 代码


```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 重复数据避免多次删除
        if(nums.size() < 1) return 0;
        int head_cur = 0; // 指向当前判断数据
        int tail_cur = 1; // 指向下一个不重复数据
        nums.push_back(nums[0] - 1); // 哨兵
        while(tail_cur < nums.size()){
            while(nums[head_cur] == nums[tail_cur]) {
                ++tail_cur;
            }
            nums[++head_cur] = nums[tail_cur++];
        }
        return head_cur;
        // 多次判断是否越界
    }
};
```