### 解题思路
时间复杂度O(N) 空间复杂度O(1)

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if (nums.size() <= 1)
        {
            return nums.size();
        }

        int j = 1;
        int count = 1; //当前元素出现个数

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums.at(i - 1) == nums.at(i))
            {
                ++count;
            }
            else
            {
                count = 1;
            }

            if (count <= 2)
            {
                nums.at(j) = nums.at(i);
                ++j;
            }
        }

        return j;
    }
};
```