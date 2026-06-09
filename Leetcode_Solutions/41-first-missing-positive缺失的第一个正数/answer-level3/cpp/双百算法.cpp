![image.png](https://pic.leetcode-cn.com/3eacd2e1bf2f2c815057051c88577f1aeb84ff8c16da66f0afcabed228183309-image.png)

### 解题思路
总的思路：
1. 遍历nums，将大小为n的元素交换在n-1的位置上，
2. 再遍历一遍nums，从第一个数开始，必须是1,2,3,...若不是则返回这个缺少的数，若全部运行完则返回size+1

注意点：
1. 在遍历过程中，若发生了交换就不要++idx，否则可能会漏运算
2. 只有当前检测的位置的数既在1~size，同时自己又不在该在的位置上，要交换的位置上也不等于自己（即待交换的位置上的数没放对）
3. 注意特判输入大小为0的情况

### 代码

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        if(!len) return 1;
        int idx = 0, temp;
        while(idx < len)
        {
            if(nums[idx] <= len && nums[idx] > 0 && 
                nums[idx] != idx+1 && nums[nums[idx]-1] != nums[idx]) //!!!注意这一行的判断
            {
                swap(nums[idx], nums[nums[idx]-1]);
                continue;    
            }
            ++idx;
        }
        for(int idx = 0; idx < len; ++idx)
            if(nums[idx] != idx+1)  return idx+1;
        return len+1;
    }
};
```