1、hashmap

2、二分查找

3、使用首、尾双指针

```cpp

class Solution {
    public:
        //方法1、使用两数之和I 的解法（对一般无序数组）
        //时间复杂度O(n) 空间复杂度O(n)
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> v(2);
            unordered_map<int, int> map;
            for (int i = 0; i < nums.size(); ++i)
            {
                auto found = map.find(target - nums.at(i));
                if (found != map.end())
                {
                    //注意：这里的found->second会小于i（因为i还没存入map）
                    v.at(0) = found->second + 1;
                    v.at(1) = i + 1;

                    return v;
                }

                map.insert(pair<int, int>(nums.at(i), i));
            }

            return v;
        }

        //方法2、对有序数组 可以使用二分查找法 查找target - nums.at(i)  
        //时间复杂度O(nlogn) 空间复杂度O(1)
        int binary_search(vector<int>& nums, int target)
        {
            int left = 0;
            int right = (int)nums.size() - 1;

            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (nums.at(mid) == target)
                {
                    return mid;
                }
                else if (target < nums.at(mid))
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }	
            }

            return -1;
        }

        vector<int> twoSum(vector<int>& nums, int target) {

            vector<int> v(2);

            for (int i = 0; i < nums.size(); ++i)
            {
                int index = binary_search(nums, target - nums.at(i));
                if (index != -1  && index != i)
                {
                    if (i < index)
                    {
                        v.at(0) = i + 1;
                        v.at(1) = index + 1;
                    }
                    else
                    {
                        v.at(0) = index + 1;
                        v.at(1) = i + 1;
                    }
                    break;
                }
            }

            return v;
        }

        //方法3 有序数组 双指针
        //两个指针最开始位于首、尾，当两个指针的元素之和比target大，将尾指针左移；反之，将首指针右移，相等则直接返回（利用了数组有序性）
        //时间复杂度O(n), 空间复杂度O(1)
        vector<int> twoSum(vector<int>& nums, int target) {

            vector<int> v(2);
            int left = 0;
            int right = nums.size() - 1;

            while (left < right)
            {
                // int sum = nums.at(left) + nums.at(right); //注意：可能溢出 如：[2,7,2147483647] 9
                // if (sum == target)
                // {
                //     v.at(0) = left + 1;
                //     v.at(1) = right + 1;
                //     return v;
                // }
                // else if (sum > target)
                // {
                //     --right;
                // }
                // else
                // {
                //     ++left;
                // }

                int diff = target - nums.at(right);
                if(diff == nums.at(left))
                {
                    res.at(0) = left + 1;
                    res.at(1) = right + 1;
                    break;
                }
                else if(diff > nums.at(left))
                {
                    ++left;
                }
                else
                {
                    --right;
                }
            }

            return v;
        }
    };