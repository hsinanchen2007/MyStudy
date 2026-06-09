### 解题思路
每个数组一个指针，从前往后进行合并
最后返回中位数

### 代码

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        vector<double> nums;
        while(i<nums1.size()||j<nums2.size()){
            if(i<nums1.size()&&j<nums2.size()){
                if(nums1[i]<nums2[j]){
                    nums.push_back(nums1[i]);
                    i++;
                }else if(nums1[i]>nums2[j]){
                    nums.push_back(nums2[j]);
                    j++;
                }else{
                    nums.push_back(nums1[i]);
                    nums.push_back(nums2[j]);
                    i++;
                    j++;
                }
            }else if(i<nums1.size()){
                nums.push_back(nums1[i]);
                i++;
            }else{
                nums.push_back(nums2[j]);
                j++;
            }
        }
        int len=nums.size();
        if(len%2==1) return nums[len/2];
        else return (nums[len/2]+nums[len/2-1])/2;
    }
};
```