### 解题思路
先判断数组长度是否为0，如果为0，直接返回；
若不为0，则先定义一个diff,表示数组中不同数字的个数，其初始值为1；
然后使用一个指针i,从第二个元素开始扫描一直到最后。
每次拿一个元素与num[diff-1]的元素比较，若相同，则将指针后移一位；若不同，则将diff加一，交换第diff个数字和第i个数字，交换完后继续向后移动指针。

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len==0)
            return 0;
        //不同的数量
        int diff = 1;
        for(int i=1;i<len;i++){
            int pos = i;
            if(nums[pos]==nums[diff-1])
                continue;
            else{
                diff++;
                int temp = nums[diff-1];
                nums[diff-1] = nums[pos];
                nums[pos] = temp;
            }
        }
        return diff;
    }
};
```