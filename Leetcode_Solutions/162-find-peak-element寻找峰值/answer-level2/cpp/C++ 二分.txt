看到logN时间复杂度，考虑二分。重点在于怎么二分，按照题目的思路，可以在mid处和它左右两边的值判断一下应该取哪一边。留意边界条件
```
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size();
        while(l < r) {
            int mid = l + (r - l)/2;
            int n = nums[mid];
            int preN, nextN;
            if (mid == 0) {
                preN = INT_MIN;
            } else {
                preN = nums[mid-1];
            }
            if (mid == r - 1) {
                nextN = INT_MIN;
            } else {
                nextN = nums[mid+1];
            }
             
            if (n > preN) {
                if (n > nextN) {
                    return mid;
                } else {
                    l = mid + 1;
                }
            } else {
                r = mid;
            }
        }
        return l;
    }
};
```