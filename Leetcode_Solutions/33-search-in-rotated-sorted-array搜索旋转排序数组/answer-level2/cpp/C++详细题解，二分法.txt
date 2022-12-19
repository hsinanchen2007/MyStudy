### 思路一
直接二分法，中心点的左右两侧必有至少一侧是有序的
```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l  = 0, r = nums.size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] == target)  return mid;
            if(nums[mid] < nums[r]){
                if(nums[mid] < target && nums[r] >= target)  l = mid + 1;
                else    r = mid - 1;
            }
            else{
                if(nums[mid] > target && nums[l] <= target)  r = mid - 1;
                else    l = mid + 1;
            }
        }
        return -1;
    }
};
```
### 思路二
一开始的做法，代码缝缝补补不太好看。
- 由于算法时间复杂度必须是 O(log n) 级别，暗示要用二分法
- 因为旋转前数组为升序，旋转后旋转点两侧仍是升序，我们只需先找到旋转点的位置（使用二分法），然后判断target在前段还是后段，之后再用二分法进行查找即可
```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans = -1;
        if(nums.empty())    return ans;
        int l = 0;
        int r = nums.size() - 1;
        int minlo = l; //储存最小值的索引
        int maxlo = r; //储存最大值的索引
        if(nums.size() == 1){ //如果只有一个数字，直接判断
            if(nums[0] == target)   return 0;
            else return ans;
        }
        int templ = l;
        int tempr = r;
        while(templ <= tempr){
            int mid = templ + (tempr - templ) / 2;
            if((mid - 1 >= 0 && mid + 1 < nums.size() && nums[mid] < nums[mid - 1] && nums[mid] < nums[mid + 1]) || (mid + 1 == nums.size() && nums[mid] < nums[mid - 1]) || (mid - 1 == -1 && nums[mid + 1] > nums[mid])){
                minlo = mid;
                break;
            }
            if(nums[mid] < nums[tempr]){
                tempr = mid - 1;
            }
            else{
                templ = mid + 1;
            }
        }
        if(minlo - 1 != -1 )    maxlo = minlo - 1;
        if(target > nums[maxlo] || target < nums[minlo])    return ans; //如果在数字范围之内
        
        if(target >= nums[0])   r = maxlo; //重新设定边界----在左半段的情况      修改r值
        else if(target <= nums[r])  l = minlo; //在右半段的情况   修改l值
        else    return -1;
        while(l <= r){ //二分法常规模板
            int mid = l + (r - l) / 2;
            if(nums[mid] == target)   return mid;
            if(nums[mid] > target)    r = mid - 1;
            else    l = mid + 1;
        }
        return ans;
    }
};
```
