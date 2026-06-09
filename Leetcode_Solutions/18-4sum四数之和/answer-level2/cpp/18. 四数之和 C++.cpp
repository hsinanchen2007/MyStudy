### 解题思路
排序 + 双指针

拆分成三个函数

### 代码

```cpp
class Solution {
public:

    //两数之和  third_index为c的起始索引
    void twoSum(vector<int>& nums, int second_index, int third_index, int target2, vector<vector<int>>& res) {

        int left = third_index;
        int right = (int)nums.size() - 1;

        while (left < right)
        {
            int diff = target2 - nums.at(right); //target - a - b - d
            if (diff == nums.at(left))
            {
                res.push_back(vector<int>{ nums.at(second_index - 1), nums.at(third_index - 1), nums.at(left), nums.at(right)});

                //c去重
                //left右移到不等于当前left的值  注意：left == right也不再继续
                while (left < right && nums.at(left) == diff)
                {
                    ++left;
                }

                //d去重
                //right左移到不等于当前right的值
                int right_val = nums.at(right);
                while (left < right && nums.at(right) == right_val)
                {
                    --right;
                }
            }
            else if (diff < nums.at(left))
            {
                --right;
            }
            else
            {
                ++left;
            }
        }
    }


    //三数之和 second_index为b的起始索引
    void threeSum(vector<int>& nums, int second_index, int target3, vector<vector<int>>& res) {

        for (int i = second_index; i < nums.size() - 2; ++i)
        {
            if (nums.at(i) > 0 && nums.at(i) > target3) // b > 0 且 b > target
            {
                break;
            }

            int target2 = target3 - nums.at(i); // target - a - b

            //三数之和
            twoSum(nums, second_index, i + 1, target2, res);

            //b去重
            while (i < nums.size() - 2 && nums.at(i) == nums.at(i + 1))
            {
                ++i;
            }
        }
    }


    //四数之和
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> res;

        if (nums.size() < 4)
        {
            return res;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 3; ++i)
        {
            if (nums.at(i) > 0 && nums.at(i) > target) // a > 0 且 a > target
            {
                break;
            }

            int target3 = target - nums.at(i); // target - a

            //三数之和
            threeSum(nums, i + 1, target3, res);

            //a去重
            while (i < nums.size() - 3 && nums.at(i) == nums.at(i + 1))
            {
                ++i;
            }
        }

        return res;
    }
};
```