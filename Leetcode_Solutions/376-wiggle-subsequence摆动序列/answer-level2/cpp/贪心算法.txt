### 解题思路
当序列有一段连续的递增或递减时，为形成摇摆子序列，只需要保留这段连续的递增或递减的首尾元素，这样更可能使得尾部的后一个元素成为摇摆子序列的下一个元素。

### 代码

```cpp
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2) {
            //序列个数小于2时直接为摇摆序列
            return nums.size();
        }
        //三种状态
        static const int BEGIN = 0;
        static const int UP = 1;
        static const int DOWN = 2;
        int STATE = BEGIN;
        int max_len = 1;

        for(int i = 1; i < nums.size(); i++) {
            switch(STATE) {
                case BEGIN:
                    if(nums[i-1]<nums[i]) {
                        STATE = UP;
                        max_len++;
                    } else if (nums[i-1]>nums[i]) {
                        STATE = DOWN;
                        max_len++;
                    }
                    break;
                case UP:
                    if(nums[i-1]>nums[i]) {
                        STATE = DOWN;
                        max_len++;
                    }
                    break;
                case DOWN:
                    if(nums[i-1]<nums[i]) {
                        STATE = UP;
                        max_len++;
                    }
                    break;

            }
        }
        return max_len;

        
    }
};
```