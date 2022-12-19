### 解题思路
- 这道题是求四数之和，数据可能重复出现。可以先将传入的vector数列排序，利用双指针固定两个点，然后就转化为在这双指针范围内的新“两数之和”的问题。
- 由于之前已经将数列排序，所以可以利用同样的双指针方法解决内层的双指针问题。
- 由于存在重复数据所以，移动指针时需要注意元素重复。

### 代码

```cpp
class Solution
{
private:
    vector<vector<int>> rst;

public:
    //转化为内层有序序列的两数之和
    void twoSum(vector<int> &nums, int left, int right, int target)
    {
        int t_left = left + 1;
        int t_right = right - 1;

        while (t_left < t_right)
        {
            if ((nums[t_left] + nums[t_right]) > target)
            {
                //右移
                while (t_left < (--t_right))
                {
                    if (nums[t_right] != nums[t_right + 1])
                        break;
                }
            }
            else if ((nums[t_left] + nums[t_right]) < target)
            {
                //左移
                while ((++t_left) < t_right)
                {
                    if (nums[t_left] != nums[t_left - 1])
                        break;
                }
            }
            else
            {
                rst.push_back({nums[left], nums[t_left], nums[t_right], nums[right]});
                //左移
                while ((++t_left) < t_right)
                {
                    if (nums[t_left] != nums[t_left - 1])
                        break;
                }
                //右移
                while (t_left < (--t_right))
                {
                    if (nums[t_right] != nums[t_right + 1])
                        break;
                }
            }
        }
    }

    //四数之和
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        if (nums.size() < 4)
            return rst;

        //排序 O(NlogN)
        sort(nums.begin(), nums.end());
        for (int i = 0; i < (nums.size() - 3); ++i)
        {
            if ((i != 0) && (nums[i] == nums[i - 1]))
                continue;

            for (int j = (nums.size() - 1); j >= (i + 3); --j)
            {

                if ((j != (nums.size() - 1)) && (nums[j] == nums[j + 1]))
                    continue;

                twoSum(nums, i, j, (target - nums[i] - nums[j]));
            }
        }
        return rst;
    }
};
```