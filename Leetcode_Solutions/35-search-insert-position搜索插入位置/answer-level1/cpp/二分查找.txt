Solution1
将查找区间分为nums[lo,mi)、nums(mi,hi)、nums[mi]
进入左区间需要判断１次，进入右区间需要判断２次，直接命中需要判断３次
```
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int hi = nums.size();
        int lo = 0,mi;
        while(lo < hi){
            mi = (lo+hi)/2;
            if(target < nums[mi]) hi = mi;
            else if(nums[mi] < target) lo = mi + 1;
            else return mi;
        }
        return (lo==mi)?mi:mi+1;
    }
};
```

Solution2
将查找区间分为nums[lo,mi)、nums[mi,hi)
```
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int hi = nums.size();
        int lo = 0,mi;
        while(1 < hi-lo){
            mi = (lo+hi)/2;
            (target< nums[mi])? hi=mi:lo=mi;
        }
        return (nums[lo]<target)?lo+1:lo;
    }
};
```

Solution3 
将查找区间分为nums[lo,mi)、nums(mi,hi)
```
class Solution {
 public:
    int searchInsert(vector<int>& nums, int target) {
        int hi = nums.size();
        int lo = 0,mi;
        while(lo< hi){
            mi = (lo+hi)/2;
            (target <= nums[mi])? hi=mi:lo=mi+1;
        }
        return lo;
    }
};

```