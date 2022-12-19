### 解题思路
虽然主要是复习排序算法的，但是越优化越慢还是多少有点不爽，用了三相切分优化和局部插入排序优化。

### 代码

```cpp
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    int partition(vector<int>& nums, int lo, int hi)
    {
        int i = lo, j = hi + 1;
        int a = nums[lo];
        while(true)
        {
            while(nums[++i] <= a)
            {
                if (i == hi)
                    break;
            }
            while(nums[--j] >= a)
            {
                if (j == lo)
                    break;
            }
            if (i >= j)
                break;
            
            swap(nums[i], nums[j]);
        }

        swap(nums[lo], nums[j]);
        return j;
    }

    void insertionSort(vector<int>& nums, int lo, int hi)
    {
        int tmp;
        int j;
        for (int i = lo; i <= hi; i++)
        {
            j = i;
            tmp = nums[j];
            for (; j > 0 && tmp <= nums[j - 1]; j--)
            {
                nums[j] = nums[j - 1];
            }
            nums[j] = tmp;
        }
    }

    void quickSort(vector<int>& nums, int lo, int hi)
    {
        if (hi <= lo + 12)
        {
            insertionSort(nums, lo, hi);
            return;
        }
        // int j = partition(nums, lo, hi);
        int lt = lo, i = lo + 1, gt = hi;
        int v = nums[lo];
        while(i <= gt)
        {
            int cmp = nums[i] - v;
            if (cmp < 0) swap(nums[lt++], nums[i++]);
            else if (cmp > 0) swap(nums[i], nums[gt--]);
            else i++;
        }
        // quickSort(nums, lo, j - 1);
        // quickSort(nums, j + 1, hi);
        quickSort(nums, lo, lt - 1);
        quickSort(nums, gt + 1, hi);
    }
};
```