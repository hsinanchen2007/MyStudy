### 解题思路
用的快排的思想

### 代码

```cpp
class Solution {
    int target;
private:
    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[low];

        while (low < high) {
            while (low < high && nums[high] < pivot) {
                high--;
            }
            nums[low] = nums[high];

            while (low < high && nums[low] >= pivot) {
                low++;
            }
            nums[high] = nums[low];
        }
        nums[low] = pivot;

        return low;
    }

    void dfs(vector<int>& nums, int left, int right, int k) {
        int loc = 0;

        if (left < right) {
            loc = partition(nums, left, right);

            if (loc == target - 1) {
                return;
            } else if (loc < target - 1) {
                dfs(nums, loc + 1, right, k - loc - 1);
            } else {
                dfs(nums, left, loc - 1, k);
            }
        }

        return;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        this->target = k;

        dfs(nums, 0, nums.size() - 1, k);

        return nums[k - 1];
    }
};

```