### 解题思路
解法一（双指针）：
遍历数组，将非零元素移动到数组左边，剩余元素用0覆盖。
i表示新数组中不为0的元素下标，j表示旧数组中不为0的元素下标。
时间复杂度：O(n) 空间复杂度：O(1)

### 代码

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        while(j < nums.size()){
            if(nums[j] != 0){
                if(j != i){
                    nums[i] = nums[j];
                }
                i++;
            }
            j++;
        }

        while(i < nums.size()){
            nums[i++] = 0;
        }

    }
};
```