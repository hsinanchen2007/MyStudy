### 解题思路
题目要求:time complexity O(logn)
a.采用二分查找找出target在数组中的一个位置
b.在该位置左边部分查找target的起始位置，在该位置右边部分查找target的结束位置
c.查找起始位置和结束位置时也采用二分查找
Note:查找起始位置和结束位置时,不能直接循环比较，否者时间复杂度为O(n)
    比如：nums[]={8,8,8,8,8} target = 8
    首先nums[mid] == target，如果在mid左右两部分分别采用循环查找起始和结束，则会分别遍历n/2的数组长 度，故时间复杂度为O(n)，不过这个题目用这种方法也可以通过所有测试用例，用时8ms，击败83%左右的用户，可能是测试用例不完善，或者我时间复杂度计算有问题。

### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                ans[0] = mid;
                ans[1] = mid;

                //在mid左边部分中查找起始位置
                int left_low = 0, left_high = mid - 1;
                while (left_low <= left_high)
                {
                    int left_mid = left_low + (left_high - left_low) / 2;
                    if (nums[left_mid] == target)
                        left_high = left_mid - 1;
                    else	//nums[left_mid] < target
                        left_low = left_mid + 1;
                }
                ans[0] = left_low;

                //在mid右边部分中查找结束位置
                int right_low = mid + 1, right_high = nums.size() - 1;
                while (right_low <= right_high)
                {
                    int right_mid = right_low + (right_high - right_low) / 2;
                    if (nums[right_mid] == target)
                        right_low = right_mid + 1;
                    else	//nums[right_mid] > target
                        right_high = right_mid - 1;
                }
                ans[1] = right_low - 1;//ans[1] = right_high
                
                break;
            }
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return ans;
    }
};

//下面是采用循环查找mid左右部分中的起始和结束位置的代码
vector<int> searchRange() {
        vector<int> ans(2, -1);
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                ans[0] = mid;
                ans[1] = mid;
                int left = mid - 1, right = mid + 1;
                while (left >= 0 && nums[left] == target)
                    --left;
                ans[0] = ++left;

                while (right < nums.size() && nums[right] == target)
                    ++right;
                ans[1] = --right;

                break;
            }
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return ans;
    }
```