# 解法1：计数排序

遍历数组中的元素，对每个颜色出现的次数进行计数，将计数值存放到一个临时数组中；接着，将临时数组中的下标按照其对应的元素大小重复输入到原数组中。

```c++
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        vector<int> count(3, 0);
        for (auto num: nums){
            count[num] += 1;
        }
        nums.clear();
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < count[i]; j++){
                nums.push_back(i);
            }
        }
    }
};
```

## 解法2：快速排序

题目中要求原地排序，常数空间复杂度，只扫描一次数组。很明显的快速排序特征。

```c++
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        partition(nums, 0, nums.size() - 1);
    }

    void partition(vector<int>& nums, int start_index, int end_index){
        if (start_index >= end_index)
            return;
        int selected_index = randomInRange(start_index, end_index);
        swap(nums[selected_index], nums[end_index]);
        int small_index = start_index - 1;
        for (int i = start_index; i <= end_index - 1; i++){
            if (nums[i] < nums[end_index]){
                swap(nums[small_index + 1], nums[i]);
                small_index++;
            }
        }
        swap(nums[small_index + 1], nums[end_index]);
        partition(nums, start_index, small_index);  // 处理左侧半部分
        partition(nums, small_index + 2, end_index);  // 处理右侧半部分
    }

    int randomInRange(int start_index, int end_index){
        return rand() % (end_index - start_index + 1) + start_index;
    }
};
```
![image-20200309235440553.png](https://pic.leetcode-cn.com/397afa789afa5edc55f65326116c98e9781c524bb3ae81dade42ee58389c8ac6-image-20200309235440553.png)


