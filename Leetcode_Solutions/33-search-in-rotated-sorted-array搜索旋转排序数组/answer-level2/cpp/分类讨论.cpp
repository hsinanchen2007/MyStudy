### 解题思路
执行用时 :4 ms, 在所有 C++ 提交中击败了90.71% 的用户
内存消耗 :9 MB, 在所有 C++ 提交中击败了5.13%的用户
分成target大于左边的数 或者 小于 最右边的数 然后再讨论。
### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return -1;
        int res = find(nums, 0, nums.size() - 1, target);
        return res;
    }

    int find(vector<int>& nums, int left, int right, int target)
    {
        int res = -1;
        if (left > right)
            return res;
        else if (target == nums[right])
            return right;
        else if (target == nums[left])
            return left;
        else if (target > nums[left])
        {
            int mid = (left + right) / 2;
            if (target == nums[mid])
                return mid;
            else if (target < nums[mid])
                res = bifind(nums, 0, mid - 1, target);
            else if (target > nums[mid])
            {
                if (nums[mid] >= nums[left])
                    res = find(nums, mid + 1, right, target);
                else
                    res = find(nums, 0, mid - 1, target);
            }
        }
        else if (target < nums[right])
        {
            int mid = (left + right) / 2;
            if (target == nums[mid])
                return mid;
            else if (target > nums[mid])
                res = bifind(nums, mid + 1, right, target);
            else if (target < nums[mid])
                if (nums[mid] <= nums[right])
                    res = find(nums, 0, mid - 1, target);
                else
                    res = find(nums, mid + 1, right, target);
        }
        return res;
    }

    int bifind(vector<int>& nums, int left, int right, int target)
    {
        if (left > right)
            return -1;
        int mid = (left + right) / 2;
        if (nums[mid] > target)
            return bifind(nums, left, mid - 1, target);
        else if (nums[mid] < target)
            return bifind(nums, mid + 1, right, target);
        else if (nums[mid] == target)
            return mid;
        return -1;
    }
};
```