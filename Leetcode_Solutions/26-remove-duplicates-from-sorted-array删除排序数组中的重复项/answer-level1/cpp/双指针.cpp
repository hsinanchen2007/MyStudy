### 解题思路
一个慢指针指示目前排列在前面的最新的不同值存在的位置，一个快指针在每次发现新的不同值的时候，将不同的值插入慢指针的下一位，而后在遍历该段相同值的时候不会发生覆盖，因为此时是与之前交换位置的该段值第一个比较，他们相同。

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)return 0;
        int i = 0;
        int len = 1;
        for (int j = 1 ; j < nums.size() ; j++){
            if(nums[j] != nums[i]){
                i++;
                nums[i] = nums[j];
                len++;
            }
        }
        return len;
    }
};
```