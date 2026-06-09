## 思路一：排序
先全局排序，再从第二个元素开始逐对交换元素的位置。
### 代码
时间复杂度：O(nlogn)，取决于排序
空间复杂度：O(1)
```c++
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for (int i = 1; i < size-1; i+=2) {
            swap(nums[i], nums[i+1]);        
        }            
    }
};
```

## 思路二：就地比较
当我们遍历整个数组，比较当前元素与下一个元素。若顺序不正确，则交换之。
### 代码
时间复杂度：O(n)
空间复杂度：O(1)
```c++
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int size = nums.size();
        for (int i = 0; i < size - 1; ++i) {
            if ((i % 2 == 0 && nums[i] > nums[i+1]) || (i % 2 == 1 && nums[i] < nums[i+1])) {
                swap(nums[i], nums[i+1]);
            }
        }         
    }
};
```
