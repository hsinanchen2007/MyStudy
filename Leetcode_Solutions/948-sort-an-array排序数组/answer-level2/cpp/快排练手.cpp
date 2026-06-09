### 解题思路
双指针快排

### 代码

```cpp
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        Qsort(nums, low, high);
        return nums;
    }
    void Qsort(vector<int>& nums, int low, int high){
         /*快排
         双指针*/
        if(low < high){
            int flag = Partition(nums, low, high);//确定中枢轴，将nums划成两部分
            Qsort(nums, low, flag - 1);//递归对前部分进行排序
            Qsort(nums, flag + 1, high);//递归对后部分进行排序
        }
    }
    int Partition(vector<int>&nums, int low, int high){
        /*
        确定划分的位置
        */
        int key = nums[low];
        int temp;
        while(low < high){
            while(low < high && nums[high] >= key)
                high--;
            temp = nums[low];
            nums[low] = nums[high];
            nums[high] = temp;
            while(low < high && nums[low] <= key)
                low++;
            temp = nums[low];
            nums[low] = nums[high];
            nums[high] = temp;
        }
        return low;
    }
};
```