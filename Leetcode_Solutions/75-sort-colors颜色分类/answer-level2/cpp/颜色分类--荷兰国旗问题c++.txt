### 解题思路
Partition进阶：三向切分
与传统partition不同，这里设置三个指针；从左到右扫描数组一次，通过交换实现排序；

### 代码

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int less = 0;
        int cur = 0;
        int more = len-1;
        int target = 1;

        while(cur <= more){
            if(nums[cur] < target){
                swap(nums[cur++],nums[less++]);
            }else if(nums[cur] > target){
                swap(nums[cur],nums[more--]);
            }else
            cur++;
        }
    }
};
```