### 解题思路

由题意知本题采用二分法，要点在于每次根据mid的值去赋值给begin或者end，一旦mid等于target，则基于mid进行左右两侧的查找。
本解法不是最优解法，在mid等于target之后也可以采用二分搜索起始和终点，但是出于时空均衡考虑仅采用地毯式搜索。
最终耗时4ms， 超过98.8%， 内存消耗10.3M，超过85.8%

### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        if (nums.size() == 0)
            return {-1, -1};

        int begin = 0, end = nums.size() - 1;

        if (nums[begin] > target || nums[end] < target)
            return {-1, -1};

        while (begin <= end)
        {
            if (nums[begin] == target && nums[end] == target)
            {
                vector<int> ret = {begin, end};
                return ret;
            }

            int mid = (begin + end) / 2; 
            if (nums[mid] < target)
                begin = mid + 1;
            else if (nums[mid] > target)
                end = mid - 1;
            else
            {
                begin = mid;
                end = mid;
                while (begin >= 0 && nums[begin] == target)
                {
                    begin--;
                }
                while (end < nums.size() && nums[end] == target)
                {
                    end++;
                }
                vector<int> ret = {begin + 1, end - 1};
                return ret;               
            }

            if (nums[begin] > target || nums[end] < target)
            {
                return {-1, -1};
            }
        }

        return {-1, -1};
    }
};
```