```
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n) { // to ensure m<=n
            return findMedianSortedArrays(nums2,nums1);
        }
        int iMin = 0, iMax = m;   /*i为0时 left_A为空 i为m时right_A为空 */
        int halfLen=(m + n + 1) / 2;
/*
1.len_left=len_right : i+j=m−i+n−j ---> j=(m+n)/2-i
2.len_left=len_right+1: i+j=m-i+n-j+1 ---> j=(m+n+1)/2-i
当m+n为奇数时，为了确保中位数出现在左半边，需要满足条件2：len_left=len_right+1;
当m+n为偶数时,需要满足条件1：len_left=len_right。
同时，当m+n为偶数，在整除运算中 (m+n+1)/2=(m+n)/2，len_left=len_right也成立，即取halflen为(m+n+1)/2同时满足了m+n为奇数和偶数的条件。
*/
        int maxLeft=INT_MIN;
        int minRight=INT_MAX;
        while (iMin <= iMax) {
            int i = (iMin + iMax) / 2;
            int j = halfLen - i;
            if (i < iMax && nums2[j-1] > nums1[i]){ //i太小了
                iMin = i + 1; 
            }
            else if (i > iMin && nums1[i-1] > nums2[j]) { //i太大了
                iMax = i - 1; 
            }
            else { // i 找到了
                
                if (i == 0) { maxLeft = nums2[j-1]; }
                else if (j == 0) { maxLeft = nums1[i-1]; }
                else { maxLeft =max(nums1[i-1], nums2[j-1]); }
                if ( (m + n) % 2 == 1 ) { return maxLeft; }

                
                if (i == m) { minRight = nums2[j]; }
                else if (j == n) { minRight = nums1[i]; }
                else { minRight = min(nums2[j], nums1[i]); }

                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;


        
        
    }
};
```
