### 解题思路
题目要求时间复杂度是logN，所以采取二分查找算法。定义两个全局遍历first = nums.size(), last = -1,然后每次递归时和一般二分查找递归算法一样，不同之处在于：如果找到一个等于target的下标mid时，当mid<first, 则first=mid， 当mid>last, z则last = mid。不停止，继续递归。所有递归结束后返回正确的结果。

### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        this->first = nums.size(), this->last = -1;
        binarySearch(nums, 0, nums.size() - 1, target);
        this->first = (nums.size() == this->first) ? -1: this->first;
        this->last = (-1 == this->last) ? -1 : this->last;
        return {this->first, this->last};
    }

    int first, last;
    void binarySearch(vector<int>& nums, int left, int right, int target)
    {
        if(left > right)
            return;
        int mid = (left + right) / 2;
        if(nums[mid] == target){
            this->first = (mid < this->first) ? mid : this->first;
            this->last = (mid > this->last) ? mid : this->last;
        }
        binarySearch(nums, left, mid - 1, target);
        binarySearch(nums, mid + 1, right, target);
    }
};
```