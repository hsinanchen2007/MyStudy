### 解题思路
并行二分法，即每次循环进行两次二分，分别用于定位左侧和右侧位置

### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        if (nums.empty() || nums[0]>target || nums[n-1]<target) return {-1,-1};
        int left1=0,left2=0,right1=n-1,right2=n-1;
        int center1=(left1+right1)/2,center2=(left2+right2)/2;
        while (left1<right1 || left2<right2){
            if (left1<right1) {
                if (nums[center1]==target) {
                    if ((center1!=0 && nums[center1-1]<target) || center1==0) left1=right1;
                    else {
                        right1=center1-1;
                        center1=(left1+right1)/2;
                    }
                }
                else if (nums[center1]<target) {
                    left1=center1+1;
                    center1=(left1+right1)/2;
                }
                else if (nums[center1]>target) {
                    right1=center1-1;
                    center1=(left1+right1)/2;
                }
            }
            if (left2<right2) {
                if (nums[center2]==target) {
                    if ((center2!=n-1 && nums[center2+1]>target) || center2==n-1) left2=right2;
                    else {
                        left2=center2+1;
                        center2=(left2+right2)/2;
                    }
                }
                else if (nums[center2]<target) {
                    left2=center2+1;
                    center2=(left2+right2)/2;
                }
                else if (nums[center2]>target) {
                    right2=center2-1;
                    center2=(left2+right2)/2;
                }
            }

        }
         if (nums[center1]==target) return {center1,center2};
         else return {-1,-1};
        
    }
};
```