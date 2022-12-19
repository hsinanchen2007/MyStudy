### 解题思路

思路很简单，就是把大问题变成两个问题

- 在有重复值的数组，查找第一个等于指定值的位置
- 在有重复值的数组，查找最后一个等于指定值的位置

整体代码都和常规二分一摸一样，只有在mid==target时不同

```cpp
        int low = 0, high = nums.size() - 1;

        while (low <= high){
            int mid = low + (high-low) / 2;
            if ( nums[mid] == target){
                 //此处不同
            } else if (nums[mid] < target ){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
```

如果是查找第一个，作如下检查

- 是不是数组第一个位置，前一个位置是不是比给定值小。
  - 如果满足说明找到了，
  - 不满足，说明靠后了，high = mid - 1

如果是查找最后一个，作如下检查

- 是不是数组最后一个个位置或者，后一个位置是不是比给定值大。
  - 如果满足说明找到了，
  - 不满足，说明靠前了，low = mid + 1


### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int start = findFirst(nums, target);
        int end = findLast(nums, target);

        vector<int>res(2,0);
        res[0] = start, res[1] = end;
        return res;

    }

    int findFirst(vector<int>& nums, int target){
        int low = 0, high = nums.size() - 1;

        while (low <= high){
            int mid = low + (high-low) / 2;
            if ( nums[mid] == target){
                if ( mid == 0 || nums[mid-1] < target)  return mid;
                high = mid - 1;
            } else if (nums[mid] < target ){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
    int findLast(vector<int>& nums, int target){
        int low = 0, high = nums.size() - 1;

        while (low <= high){
            int mid = low + (high-low) / 2;
            if ( nums[mid] == target){
                if ( mid == nums.size() - 1 || nums[mid+1] > target)  return mid;
                low = mid + 1;
            } else if (nums[mid] < target ){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
};
```

如果在面试的时候遇到，是不是可以问下主考官，我能不能调用库函数呢（笑）. 

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto begin = lower_bound(nums.begin(), nums.end(), target);
        auto end   = upper_bound(nums.begin(), nums.end(), target);

        if ( begin == end ) return {-1,-1}; 
        return {(int)(begin - nums.begin()), (int)(end- nums.begin()-1)};

    }
};
```