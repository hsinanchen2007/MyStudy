由于数组中的数均为整数，所以可以采用插入target-0.5,tatget+0.5的思路，
通过二分法寻找target-0.5,tatget+0.5应该插入的地方，两个位置的间距就是target


```
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int first = bitSearch(nums, target-0.5);
        int last = bitSearch(nums, target+0.5);
        return last- first;
    }

    int bitSearch(vector<int> &nums, double target)
    {
        int start = 0, end = nums.size()-1;
        while(start <= end)
        {
            int mid = start + ((end-start)>>1);
            if(nums[mid] < target)
                start = mid+1;
            else if(nums[mid] > target)
                end = mid-1;
        }
        return start;
    }
};
```
