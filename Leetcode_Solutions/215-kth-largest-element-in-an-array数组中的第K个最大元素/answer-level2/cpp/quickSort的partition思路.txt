```
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /*
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
        */
        
        int size = nums.size();
        int ultimateIdx = size - k;
        int left = 0, right = size-1;
        int pivotIdx;
        while ((pivotIdx = partition(nums, left, right)) != ultimateIdx) {
            // partition每次会将一个pivot固定到最终位置处
            if (pivotIdx < ultimateIdx) {
                left = pivotIdx + 1;
            } else {
                right = pivotIdx - 1;
            }
        }
        
        return nums[ultimateIdx];
    }
    
    int selectPivot(vector<int>& nums, int left, int right) {
        // 在当前子数组中选择枢纽元
        // 并将枢纽元与nums[left] 交换
        // 不记得随机数怎么用了，直接随便选一个
        int idx = (left + right) / 2;
        swap(nums, left, idx);
        
        return left;
    }
    
    void swap(vector<int>& nums, int i, int j) {
        if (i == j) return;
        
        // 这种方法需要避免自己和自己进行异或
        nums[i] ^= nums[j];
        nums[j] ^= nums[i];
        nums[i] ^= nums[j];
    }
    
    int partition(vector<int>& nums, int left, int right) {
        // 选定枢纽元，并返回枢纽元在数组中的最终位置
        int pivotIdx = selectPivot(nums, left, right);
        int pivot = nums[pivotIdx];
        // 选定的pivot均放在left处
        // 此时nums[left]被空出来
        int l = left, r = left+1;    //双指针进行单向partition
        while (r <= right) {
            if (nums[r] > pivot) ++r;
            else {
                // 把比pivot小的元素放进坑里，再把坑右边的元素放到该元素原本的位置处
                // 坑右边变成了新的坑
                nums[l++] = nums[r];
                nums[r++] = nums[l];
            }
        }
        nums[l] = pivot;
        
        return l;
    }
};
```
