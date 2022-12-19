```
class Solution {
public:
    // 想法1：先找出一个数字，然后分别向前向后遍历找到程度
    // 想法2：二分法分别找到第一个的索引first和最后一个的索引last，长度=last-first+1
    int search(vector<int>& nums, int target) {
        int a = first(nums, target);
        int b = last(nums, target);
        if(a==-1)
            return 0;
        return b-a+1;
    }
    int first(vector<int>& nums, int target){
        int left=0, right=nums.size()-1;
        int mid = (left+right)/2;
        while(left<=right){  // 必须有等于
            if(nums[mid]<target)
                left = mid+1;
            else if(nums[mid]>target)
                right = mid-1;
            else{
                if(mid==0||nums[mid-1]!=nums[mid])
                    return mid;
                else{
                    right = mid;
                }
            }
            mid = (left+right)/2;
        }
        return -1;
    }

    int last(vector<int>& nums, int target){
        int left=0, right=nums.size()-1;
        int mid = (left+right)/2;
        while(left<=right){   // 必须有等于
            if(nums[mid]<target)
                left = mid+1;
            else if(nums[mid]>target)
                right = mid-1;
            else{
                if(mid==nums.size()-1 || nums[mid+1]!=nums[mid]){
                    return mid;
                }
                else{
                    left = mid+1;
                }
            }
            mid = (left+right)/2;
        }
        return -1;  // 找不见的数返回-1
    }
};
```
