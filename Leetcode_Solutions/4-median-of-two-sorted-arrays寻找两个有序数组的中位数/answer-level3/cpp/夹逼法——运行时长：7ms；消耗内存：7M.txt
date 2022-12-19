### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int f1 = 0;
        int f2 = 0;
        int r1 = nums1.size()-1;
        int r2 = nums2.size()-1;
  
        if(r1 == -1){
            int temp = r2-f2;
            if(temp%2 ==0){
                return nums2[temp/2];
            }else {
                return (static_cast<double>(nums2[temp/2]+nums2[temp/2+1]))/2;
            }
        }
        if(r2 == -1){
            int temp = r1-f1;
            if(temp%2 ==0){
                return nums1[temp/2];
            }else {
                return (static_cast<double>(nums1[temp/2]+nums1[temp/2+1]))/2;
            }
        }

        while(f1<=r1 && f2<=r2){
            if(f1 == r1 && f2 == r2){
                return (static_cast<double>(nums1[f1]+nums2[f2]))/2;
            }
            if(nums1[r1] < nums2[r2]){
                r2=r2-1;
            } else{
                r1= r1-1;;
            }
            if(nums1[f1] < nums2[f2]){
                f1++;
            }else {
                f2++;
            }
        }
        if(r1 <f1 ){
            if(f2 == r2){
                return nums2[f2];
            }else{
                int temp = r2-f2;
                if(temp%2 ==0){
                    return nums2[f2+temp/2];
                }else {
                    return (static_cast<double>(nums2[f2+temp/2]+nums2[f2+temp/2+1]))/2;
                }
            }
        }else if( r2 < f2){
            if(f1 == r1){
                return nums1[f1];
            }else{
                int temp = r1-f1;
                if(temp%2 ==0){
                    return nums1[f1+temp/2];
                }else {
                    return (static_cast<double>(nums1[f1+temp/2]+nums1[f1+temp/2+1]))/2;
                }
            }
        }
        return 0;
    }
};
```