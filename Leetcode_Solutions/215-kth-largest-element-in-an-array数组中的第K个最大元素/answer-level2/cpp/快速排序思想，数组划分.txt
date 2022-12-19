利用快速排序思想，对数组进行划分，并且判断划分的边界元素位置mid是否为第k大的数(k - 1)；
若是则返回该数，若mid > k - 1说明第k大的数在左半边数组里；若mid < k - 1说明在右半边数组里。对其继续进行数组划分，直到找到第k大的数。
数组划分函数partation采用数组中心位置的元素值作为bound（边界），也可以采用随机元素，最好不要用第一个（最后一个）元素，防止数组绝大部分元素是有序的，影响查找效率。
 ```angelscript
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int low = 0, high = nums.size() - 1, mid = 0;
        while (low <= high) {
            mid = partation(nums, low, high);
            if (mid == k - 1) return nums[mid];
            else if (mid > k - 1) high = mid - 1;
            else low = mid + 1;
        }
        //  实际上返回 -1 代表没有第 k 大的数，这里不存在
        return -1;
    }
    
    int partation(vector<int>& nums, int low, int high) {
        int left = low + 1, right = high;
        swap(nums[low], nums[(low + high) / 2]);
        int bound = nums[low];
        //  双指针，快速排序，交换不符合条件的数据
        while (left <= right) {
            while (left < high && nums[left] >= bound) left++;
            while (nums[right] < bound) right--;
            if (left < right) 
                swap(nums[left++], nums[right--]);
            else break;
        }
        //  将bound放到换分完成后的两个数组之间，作为边界, 返回bound的位次
        swap(nums[low], nums[right]);
        return right;
    }
};
```