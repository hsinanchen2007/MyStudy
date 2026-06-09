点赞第一的的异或方法我也尝试做了，但是个人觉得需要分情况讨论，挺复杂的，大于等于小于等于也容易弄错。大家可以比较一下两种方法。
看题目，明显是要用二分查找法的，这里强烈推荐看这个模板，无敌好用，不多说。
[力扣35题，十分好用的二分查找法模板](https://leetcode-cn.com/problems/search-insert-position/solution/te-bie-hao-yong-de-er-fen-cha-fa-fa-mo-ban-python-/)
题目思路：当nums[mid]>=nums[l]时，如数组[2,3,4,5,6,1],说明前半部分有序。if（nums[l]<=target && target<=nums[mid]），说明target在前半部分中，题目就简化为在普通有序数组查找一个数了；else 说明target在后半部分中，后半部分是无序的，继续将无序部分一分为二，其中一部分有序，一部分无序。当nums[mid]<nums[l],如数组[6,1,2,3,4,5],说明数组后半部分有序。剩下思路与前面一致。
每次循环先找有序的那部分，当target在有序部分中时，就变成了普通二分查找了。如果target在无序部分，就继续对无序部分一分为二，直到target在有序部分为止。
```
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0)
            return -1;
        int r = n-1;
        int l = 0;
        while(l<r)
        {
            int mid = (r-l)/2+l;
            if(nums[mid]>=nums[l])
            {
                if(nums[l]<=target && target<=nums[mid])
                    r=mid;
                else
                    l=mid+1;
            }
            else
            {
                if(nums[mid+1]<=target && nums[r]>=target)
                    l=mid+1;
                else
                    r=mid;
            }
        }
        return nums[l] == target ? l:-1;
    }
};
```
