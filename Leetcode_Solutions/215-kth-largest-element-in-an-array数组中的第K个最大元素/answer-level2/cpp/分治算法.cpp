### 解题思路
**分治算法：**
    处理类似于快速排序，通过确定一个基准元素的位置，判断该元素位置是否和要找的第k大元素的位置相同。相同则返回，否则，缩小查找区间。
    如`3 2 1 4 5`，在下标[0,4]中要查找第二大的数,即4，下标为3。选`3` 为基准元素，即下标0的位置的数。经过一轮partion后3被放置在按照排序算法确定的最终位置。即一轮partion后，变为`2 1 3 4 5` 。由于元素`3`的index为`2`比index3小（不相等）。故缩小区间[3,4],，在`3 2 1 **4 5**` 中的 4，5 中间找。直到找到下标为3的那个元素（即元素4）。

### 代码

```cpp
class Solution{

public:

    void swap(int& num1, int& num2){
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }
    //第一种partion实现
    // int partion(vector<int>&nums, int left, int right){
    //     int pivot = nums[left];
    //     int j = left;
    //     for(int i=left+1;i<=right;i++){
    //         if(nums[i] < pivot){
    //             j++;
    //             swap(nums[i], nums[j]);
    //         }
    //     }
    //     swap(nums[j], nums[left]);
    //     return j;
    // }

    // 第二种partion实现
    int partion(vector<int>& nums, int left, int right){
        int pivot = nums[left];
        while(left < right){
            while(left < right && nums[right] >= pivot) --right;
            nums[left] = nums[right];
            while(left < right && nums[left] <= pivot) ++left ;
            nums[right] = nums[left];
        }
        nums[left] = pivot;
        return left;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size()-1;
        int index;
        int target = nums.size() - k; 
        while (true){
            index = partion(nums, left, right);
            if(index == target){
                break;
            }
            else if(index > target){
                right = index - 1;
            }
            else{
                left = index + 1;
            }
        }
        return nums[index];
    }
};

```