```
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 先二分查找 找到升序的顶峰i（也就是找到旋转点）
        // 通过之前找到的顶峰，将数组分成两个 有序的子数组，对这两个有序的子数组进行二分查找
        
        if (nums.size() == 0) return -1;
        if (nums.size() == 1) {
            if (nums[0] == target) return 0;
            else return -1;
        }
        // 到这里，nums.size() >= 2
        // 注意到一个特点，顶峰i以及i左边的数都比 i右边的数要大
        // 若出现第一个元素比最后一个元素小的情况，没有进行旋转
        if (nums.front() < nums.back()) return binSearch(nums, 0, nums.size()-1, target);
        
        int topIdx = binSearchForTop(nums);
        int idx1 = binSearch(nums, 0, topIdx, target);
        int idx2 = binSearch(nums, topIdx+1, nums.size()-1, target);
        
        if (idx1 != -1) return idx1;
        if (idx2 != -1) return idx2;
        return -1;
    }
    
    int binSearchForTop(vector<int>& nums) {
        // 默认数组经过旋转
        // 默认 nums.size() >= 2
        // 找到 nums[i] > nums[i+1] 的位置
        // 如何判断当前处于顶峰点的左边还是右边？
        // 1. 若当前元素大于最右边的元素，则处于顶峰点的左边，或就是顶峰点。此时判断当前元素是否大于右边的元素，
        //    若大于，则为顶峰点，否则不是顶峰点
        // 2. 若 1. 不成立，则当前元素处于顶峰的右边
        int left = 0, right = nums.size();
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums.back()) {
                // 处于顶峰点的左边 or 就是顶峰点
                // 由于判断方法是和数组的最后一个元素比较，因此此时 mid 不可能是最右边的元素，所以不用当心越界问题
                if (nums[mid] > nums[mid+1]) return mid;
                left = mid + 1;
            } else {
                // 处于顶峰点的右边
                right = mid - 1;
            }
        }
        
        // 本解法中，一定存在顶峰点，因此不会执行到这里
        return -1;
    }
    
    int binSearch(vector<int>& nums, int left, int right, int target) {
        // 这里 topIdx+1 越界的情况，已经被 while (left <= right) 考虑到了
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};
```
