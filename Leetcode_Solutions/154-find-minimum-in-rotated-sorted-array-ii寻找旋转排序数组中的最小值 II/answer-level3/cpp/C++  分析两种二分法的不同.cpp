
基本思路：
每次选取的中点mid，会将 [left, right] 划分为两个区间，[left, mid] 和 [mid + 1, right]
那么易知，保持递增的区间不含有最小元素，可被舍去，问题规模缩小一半。

具体措施：
每次用 nums[left]（或者nums[right]）和 nums[mid] 作比较，即可找出一个递增区间，例如 
```
if(nums[mid] <= nums[right])
    right = mid;
else
    left = mid + 1;
```


问题难点：
1.除非数组整体有序，否则有大前提 nums[left] >= nums[right]。

2.当 nums[mid] == nums[right] == nums[left] 时，递增区间无法找到，如：10111 和 11101。
此时，可使用 right-- 进行快速处理。
在进行后续判断的时候，即使 nums[mid] == nums[right]，因为有 nums[left] != nums[mid], 
说明 nums[left] > nums[mid]，进而可证明 [mid + 1, right] 是元素均相等的递增区间。

3.使用 nums[left ]或 nums[right] 寻找递增区间时，情况有所不同。
用 nums[left] 判断：数组前半段是否递增，是的话则删除前半段，否则删除后半段；
用 nums[right] 判断：数组后半段是否递增，是的话则删除后半段，否则删除前半段。
如果数组前后两段都是递增区间，即数组整体递增，nums[left]会错误删除最优解，需要进行额外判断。

```
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while(left < right){
            int mid = (left + right) / 2;
            if(nums[mid] == nums[left] && nums[mid] == nums[right])
                right--;
            else if(nums[mid] <= nums[right])    //[mid, right]连续
                right = mid;
            else                            //[left, mid]连续
                left = mid + 1;    
        }
        return nums[left];
    }
};
```

```
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while(left < right){
            if(nums[left] < nums[right])
                return nums[left];
            int mid = (left + right) / 2;
            if(nums[mid] == nums[left] && nums[mid] == nums[right])
                right--;
            else if(nums[left] <= nums[mid])    //[left, mid]连续
                left = mid + 1;
            else                            //[mid, right]连续
                right = mid;    
        }
        return nums[left];
    }
};
```

