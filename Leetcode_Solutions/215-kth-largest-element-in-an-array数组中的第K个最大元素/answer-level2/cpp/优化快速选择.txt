### 解题思路
快速选择之前将选择头、尾、中三者中大小居中的（代码简单粗暴）
![捕获.PNG](https://pic.leetcode-cn.com/3570cb6d3614a5ceace2a7c6be4b4ad02befc9698e9f20ccdcdd7a0a1c7ebd1a-%E6%8D%95%E8%8E%B7.PNG)

### 代码

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKth(nums, k-1, 0, nums.size()-1);//下标要-1
    }
private:
    int findKth(vector<int>& nums, int k, int low, int high){
        int key, i{low}, j{high};
        int mid = (low + high) / 2;
        if(((nums[low] >= nums[mid]) && (nums[low] <= nums[high])) || ((nums[low] <= nums[mid]) && (nums[low] >= nums[high])))
            key = nums[low];
        else if(((nums[mid] >= nums[low]) && (nums[mid] <= nums[high])) || ((nums[mid] <= nums[low]) && (nums[mid] >= nums[high]))){
            key = nums[mid];
            nums[mid] = nums[low];
        }
        else{
            key = nums[high];
            nums[high] = nums[low];
        }
        while(i < j){
            while(i < j && nums[j] <= key) j--;
            nums[i] = nums[j];
            while(i < j && nums[i] >= key) i++;
            nums[j] = nums[i];
        }
        nums[i] = key;
        if(i == k) return nums[i];
        else if(i > k)
            return findKth(nums, k, low, i-1);
        else
            return findKth(nums, k, i+1, high);
    }
};
```