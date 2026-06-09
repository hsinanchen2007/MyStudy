### 解题思路
1. 用快速排序，然后取 nums.size() - k 的位置就是所需要的值。
2. 算法复杂度分析，快速排序的算法复杂度是 O(nlgn)，即为该解法的复杂度。


//
Note: 优先队列解法的算法复杂度由于此方法，为 O(nlgk)，当n特别大时，优先队列（小堆）法性能优势更明显，可以参见 [https://leetcode-cn.com/problems/kth-largest-element-in-an-array/solution/c-sol-you-xian-dui-lie-jie-fa-by-silverblg/](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/solution/c-sol-you-xian-dui-lie-jie-fa-by-silverblg/)

### 代码

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) { // 快速排序解法
        quicksort(nums, 0, nums.size()-1);
        return nums[nums.size() - k];
    }

    void quicksort(vector<int>& nums, int l, int r) {
        if (l>=r) return;

        int p = partition(nums, l, r);
        quicksort(nums, l, p-1);
        quicksort(nums, p+1, r);
    }

    int partition(vector<int>& nums, int l, int r) {
        srand(time_t(0));
        swap(nums[rand()%(r-l+1)+l], nums[r]);

        int i = l, j = l;
        for (; j<r; j++) {
            if (nums[j] < nums[r]) {
                swap(nums[i++], nums[j]);
            }
        }

        swap(nums[i], nums[r]);
        return i;
    }
};
```