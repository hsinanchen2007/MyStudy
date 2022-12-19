# 4. 寻找两个有序数组的中位数
最简单暴力的方法：
1. 先创建一个vector nums3，并将nums1和nums2中的元素都放入nums3中；
2. 使用sort函数将nums3排序；
3. 获取nums3的长度，并返回中位数。
```
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3 = nums1;
        nums3.insert(nums3.end(),nums2.begin(),nums2.end());
        sort(nums3.begin(),nums3.end());
        if( nums3.size()%2 == 0 ){
        	return ((double)nums3[nums3.size()/2-1]+(double)nums3[nums3.size()/2])/2;
        }else{
        	return (double)nums3[nums3.size()/2];
        }
    }
};
```
