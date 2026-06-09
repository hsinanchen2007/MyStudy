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
        int i = l;
        for(int j=l+1; j<=r; j++) {
            if(nums[j] >= pivot) swap(nums[++i], nums[j]);
        }
        swap(nums[l], nums[i]);
        return i;
    }
};
```
