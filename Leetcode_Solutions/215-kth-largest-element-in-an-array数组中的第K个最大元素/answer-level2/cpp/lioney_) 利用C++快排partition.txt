```
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while(true) {
            int n = partition(nums, left, right);
            if(n == k-1) return nums[n];
            else if(n > k-1) right--;
            else left++;
        }
    }
    int partition(vector<int>& nums, int l, int r) {
        int pivot = nums[l];
        int left = l+1, right = r;
        while(left <= right) {
            if(nums[left] < pivot && nums[right] > pivot) {
                swap(nums[left++], nums[right--]);
            }
            if(nums[left] >= pivot) left++;
            if(nums[right] <= pivot) right--;
        }
        swap(nums[l], nums[right]);
        return right;
    }
};
```
