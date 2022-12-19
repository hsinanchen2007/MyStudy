### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int midleft(vector<int> &nums, int target)
    {
        int i = 0, j = nums.size() - 1, mid;
        while (i < j)
        {
            mid = (i + j) / 2;
            if (nums[mid] < target)
            {
                i = mid + 1;
            }
            else if (nums[mid] == target)
            {
                j = mid;
            }
            else
            {
                j = mid - 1;
            }
        }
        if (j < 0)
        {
            return -1;
        }
        else if (nums[j] != target)
        {
            return -1;
        }
        return j;
    }
    int midright(vector<int> &nums, int target)
    {
        int i = 0, j = nums.size() - 1, mid;
        while (i < j)
        {
            mid = (i + j + 1) / 2;//靠右点
            if (nums[mid] < target)
            {
                i = mid + 1;
            }
            else if (nums[mid] == target)
            {
                i = mid;
            }
            else
            {
                j = mid - 1;
            }
        }
        if (j < 0)
        {
            return -1;
        }
        else if (nums[j] != target)
        {
            return -1;
        }
        return j;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if (nums.size() == 0)
        {
            res[0] = -1;
            res[1] = -1;
            return res;
        }
        res[0] = midleft(nums, target);
        res[1] = midright(nums, target);
        return res;

    }
};
```