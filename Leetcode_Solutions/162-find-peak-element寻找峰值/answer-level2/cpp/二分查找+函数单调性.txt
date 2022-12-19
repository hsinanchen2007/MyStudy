### 解题思路
1、相邻两个数不相同，即存在大小关系
2、每次二查找时，查找大于中间点的那一部分，即找凸函数部分，可以找到峰值。

### 代码

```cpp
class Solution {
public:
int findPeakElement(vector<int>& nums) {
    if(nums.size() < 2) //只有一个元素
        return 0;
    if(nums[0] > nums[1]) //峰值在边界上
        return 0;
    if(nums[nums.size() - 1] > nums[nums.size() - 2])
        return nums.size() - 1;
        
    int i = 0;
    int j = nums.size() - 1;
    while(i < j){
        int mid = i + (j - i) / 2;
        if(nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])
            return mid;
        
        if(nums[mid] < nums[mid + 1])
            i = mid;
        else
            j = mid;
    }
    
    return -1;
}
/*    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        for (; left < right; ) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }*/

};
```