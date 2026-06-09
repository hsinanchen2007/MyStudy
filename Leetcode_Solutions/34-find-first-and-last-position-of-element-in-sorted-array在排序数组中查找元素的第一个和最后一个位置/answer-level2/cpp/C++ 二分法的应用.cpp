#### 解题思路
因为需要**logn**的时间复杂度，所以就是想到**二分法**。本题目和一般的二分法还是有些变化，第一使用二分法找到有没有等于target的数组元素，找到之后在向前和向后分别使用二分法进行查找，如left找到之后就减一，来向左查找左边界，需要注意在返回时要将。
```
left++
```

### 代码
```
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) { 
        int l=0,r=nums.size()-1;
        while (l<=r){
            int mid = (l+r)/2;
            if(nums[mid]==target) {
                  int left=mid,right = mid;
                  while(left>=0&&nums[left]==target)
                  {left=search(0,left,target,nums)-1;}
                  while(right<=nums.size()-1&&nums[right]==target)
                  {right=search(right,nums.size()-1,target,nums)+1;}
                  return {left+1,right-1}; 
            }
            if(nums[mid]<target){l=mid+1;}
            else {r=mid-1;}
        }
        return {-1,-1};
    }
    int search (int l,int r,int target,vector<int>& nums){
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid]==target)return mid;
            if(nums[mid]>target)r= mid-1;
            else  l = mid+1;
        }
        return -1;
    }
};

