### 解题思路
从序列是排序的可以看出，此问题为**二分搜索** BinarySearch 的变形，暂且将在题述条件下的序列搜索称为**旋转搜索 **rotatedSearch, 那么问题可以分为：
1. 当 target 处于**完全有序**（序列中不存在旋转点 pivot )时，对该处进行**二分搜索**；
2. 当 target 处于**非完全有序**（序列中存在旋转点 pivot )时，对该处进行**旋转搜索**（递归）；

**所有的案例无非两种，旋转点在前半段或后半段**，下面举例：
1. 以 [ 2, 3, 4, 5, 0 , 1 ] 为例，**旋转点在后半段**，判断条件为 mid(4) > first(2)。那么当 target 的值在[ first, mid ] 之间时，target 处于前半段， 对前半段进行 BinarySerach，否则说明 target 在后半段的非完全有序数列中，则对后半段进行 RotateSearch；
2. 同理 [ 5, 0, 1, 2, 3, 4 ] 为例，**旋转点在前半段**，判断条件为 mid(1) < first(5)，那么当 target 的值位于[ mid, end ] 时，target 处于后半段，对后半段进行 BinarySearch，否则说明 target 在前半段的非完全序列中，对前半段进行 RotateSerach；

算法核心则为上述，具体细节见代码：

### 代码

```cpp
class Solution {
private:
    int binarySearch(vector<int>& nums, int s, int e, int target){
        if(s > e){
            return -1;
        }
        int lo = s, hi = e;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            if(nums[mid] == target){
                return mid;
            }
            else if(target < nums[mid]){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return -1;
    }
    int rotatedSearch(vector<int>& nums, int s, int e, int target){
        int fir = s, end = e; 
        if(fir > end){
            return -1;
        }               
        int mid = (fir + end) / 2;
        if(mid == fir){
            if(target == nums[mid]){
                return mid;
            }
            else if(target == nums[end]){
                return end;
            }
            return -1;
        }
        else if(nums[mid] > nums[fir]){
            if(nums[fir] <= target && target <= nums[mid]){
                return binarySearch(nums, fir, mid, target);
            }
            else{
                return rotatedSearch(nums, mid+1, end, target);
            }
        }
        else{
            if(nums[mid] <= target && target <= nums[end]){
                return binarySearch(nums, mid, end, target);
            }
            else{
                return rotatedSearch(nums, fir, mid, target);
            }
        }
    }
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return -1;
        }
        else if(nums.size() == 1){
            return (target == nums[0] ? 0 : -1);
        }
        return rotatedSearch(nums, 0, nums.size()-1, target);
    }
};
```