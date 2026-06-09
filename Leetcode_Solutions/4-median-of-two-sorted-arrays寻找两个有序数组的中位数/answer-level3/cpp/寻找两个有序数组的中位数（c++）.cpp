思路：将两个数组合成一个数组，然后排序，再求出中位数
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
     int n = nums1.size();
		int m = nums2.size();
      
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        sort(nums1.begin(), nums1.end());
        if((n+m)%2==1){
            return nums1[(n+m)/2];
        }   
            return (nums1[ (n+m-1)/2 ] + nums1[(n+m)/2] )/2.0;
        
    }
};

个人方法，有些偷巧，不喜勿喷