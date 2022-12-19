### 方法 1

题目提示里已经说明，可以使用**计数排序**：
+ 一次扫描记录 0 1 2出现的次数
+ 第二次扫描对原数组赋值


### 方法 2
这个题中，数组只有三种元素：`0 1 2`，0总是放在最前，2总是放在最后，所以**我们只要将0和2的位置放对，那么整个数组自然就有序了**

+ `left`表示左端0的位置，`righ`表示右端2的位置；`cur`遍历数组的索引
+ 如果`nums[cur] == 0`，我们只需要将当前元素和left表示的元素进行交换，并将left往后移动一位
+ 同理，如果`nums[cur] == 1`，我们只需要将当前元素和right表示的元素进行交换，并将right往前移动一位
+ 当 `cur == right`的时候，便结束循环


**时间复杂度O(n)，空间复杂度O(1)**

代码：


```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 方法1. 计数排序
        int count[3] = {0};
        for(int elem : nums){
            count[elem] += 1;
        }
        for(int i = 0, j = 0; i < 3; ++i){
            while(count[i]--){
                nums[j++] = i;
            }
        }

        // 方法2. 双指针
        int left = 0, right = nums.size() - 1, cur = 0;
        while(cur <= right){
            if(nums[cur] == 0){
                swap(nums[left++], nums[cur++]);
            }else if(nums[cur] == 2){
                swap(nums[right--], nums[cur]);
            }else{
                cur += 1;
            }
        }
    }
};
```