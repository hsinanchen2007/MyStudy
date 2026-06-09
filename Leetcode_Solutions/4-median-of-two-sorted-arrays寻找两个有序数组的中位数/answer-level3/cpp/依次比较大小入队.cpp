既然已经给你排好序了，那么我们只要定义两个游标指向两个数组，只要每次比较两个游标指向的数，小的数压入我们指定的新的vector，然后游标往后移，这样就可以以线性时间得到有序的合并后的数组。
```
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> num;
        int lm,hm;
        int p=0,q=0;
        int mlen = nums1.size();
        int nlen = nums2.size();
        int totlen = mlen + nlen;
        if(totlen%2){
        	lm = hm = totlen/2;
        } else {
        	lm = totlen/2-1;
        	hm = totlen/2;
        }
        for(int i =0; i<=hm; ++i)
        {
        	if(p<mlen && q<nlen){
        		if(nums1[p]<=nums2[q]){
        			num.push_back(nums1[p++]);
        		} else{
        			num.push_back(nums2[q++]);
        		}
        	}
        	else {
        		if(p<mlen) num.push_back(nums1[p++]);
        		else num.push_back(nums2[q++]);
        	}
        }
        double ans = 1.0*num[lm] +1.0*num[hm];
        ans = ans /2.0;
        return ans;
    }
};
```
