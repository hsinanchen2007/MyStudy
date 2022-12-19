### 解题思路

先找出旋转点，相当于找到数组两段有序，然后分别进行二分查找。


### 代码

```cpp
class Solution {
public:

    int BinarySearch(vector<int>& nums, int begin, int end, int target)
    {
        while(begin <= end)
        {
            int mid = (begin + end)/2;
            if(target > nums[mid])
            {
                begin = mid + 1;
            }
            else if(target < nums[mid])
            {
                end = mid - 1;
            }
            else
            {
                return mid;
            }
        }

        return -1;
    }

    // 找出分界点
    int GetThePoint(vector<int>& nums)
    {
        int begin = 0;
        int end = nums.size()-1;
        while(begin < end)
        {
            int mid = (begin+end)/2;
            if(nums[mid] > nums[mid+1])
            {
                return mid+1;
            }

            // 分界点不会在升序的序列里
            if(nums[mid] > nums[begin])
            {
                begin = mid+1;
            }
            else if(nums[mid] < nums[begin])
            {
                end = mid;
            }
            else
            {
                begin++;
            }
        }

        return 0;
    }

    bool search(vector<int>& nums, int target) {


        if(nums.size() == 0)
        {
            return false;
        }

        if(nums.size() == 1)
        {
            if(nums[0] == target)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        // 先找出分界点
        int index = 0;

        int point = GetThePoint(nums);
        if(point == 0)
        {
            index = BinarySearch(nums, 0, nums.size()-1, target);
            if(index < 0)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        else
        {
            index = BinarySearch(nums, 0, point-1, target);
            if(index < 0)
            {
                index = BinarySearch(nums, point,nums.size()-1, target);
                if(index < 0)
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            else
            {
                return true;
            }
        }

    }
};
```