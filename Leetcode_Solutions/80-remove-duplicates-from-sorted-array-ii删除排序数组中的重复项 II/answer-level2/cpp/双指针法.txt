### 解题思路
两根指针（i和k），一个计数器（j），当计数小于2时，将k位置上的数字存入i，并且j和i增加。当当前数字发生变化时，计数器重置为1，将k位置上的数字存入i，i增加。
k走到数组末尾时，将数组阶段为长度i，并返回i，结束。

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(!nums.size())
            return 0;
        int i = 0, j = 0, cur = nums[0];
        for(int k = 0; k < nums.size(); k++)
        {
            if(nums[k] == cur)
            {
                if(j < 2)
                {
                    nums[i] = nums[k];
                    i++;
                    j++;
                }
            }
            else
            {
                cur = nums[k];
                j = 1;
                nums[i] = nums[k];
                i++;
            }
        }
        nums.resize(i);
        return i;
    }
};
```