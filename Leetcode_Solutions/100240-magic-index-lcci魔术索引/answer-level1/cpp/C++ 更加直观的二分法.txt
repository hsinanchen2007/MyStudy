### 1. 一次遍历

最普通最简单的想法，从头开始遍历数组，遇到`i == nums[i]`的情况，直接`return i`

+ 时间复杂度为O(n)，空间复杂度为O(1)


```cpp
class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        // 1. 一次遍历
        for(int i = 0; i<nums.size(); ++i){
            if(i == nums[i]) return i;
        }
        return -1;
    }
};
```

### 2. 二分法

看了前面几位大佬的题解，个人感觉理解起来不是那么容易，并不直观，我在这里说一下我的思路：

+ `mid == nums[mid]`的话，说明mid位置是符合要求，所以需要查看是否有更小的并且符合要求的索引；对`mid - 1`的部分进行二分查找
+ 如果`mid != nums[mid]`，则我们需要对mid的两边继续二分查找
+ 也可以做一个**剪枝**，如果找到了符号要求的索引，则对大于该索引的部分不需要再查找，即`if(ret<left) return;` ret为记录找到的目标最小索引值


+ 时间复杂度为O(logn)，空间复杂度为O(1)【不考虑递归调用栈】

```cpp
class Solution {
private:
    void binary_search(vector<int>& nums, int left, int right, int& ret){
        // 这里做一个剪枝
        if(ret != -1 && ret<left) return;
        if(left <= right){
            int mid = left + (right - left) / 2;
            // 如果找到目标的索引，需要尝试能否找到更小的索引值
            if(nums[mid] == mid){
                if(ret == -1) ret = mid;
                else if(mid < ret) ret = mid;
                binary_search(nums, left, mid - 1, ret);
            // 如果mid不符合要求，则需要在mid两边继续查找
            }else{
                binary_search(nums, left, mid - 1, ret);
                binary_search(nums, mid + 1, right, ret);
            }
        }
    }
public:
    int findMagicIndex(vector<int>& nums) {
        // 2. 二分法
        int ret = -1;
        binary_search(nums, 0, nums.size()-1, ret);
    }
};
```