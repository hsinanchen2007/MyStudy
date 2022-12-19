class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int fm=0,fn=0;
        int a[10000];
        int i=0;
        while(fn!=n||fm!=m)
        {
            if(fn==n)
            a[i]=nums2[fm],i++,fm++;
            else if(fm==m)
                a[i]=nums1[fn],i++,fn++;
            else if(fn!=n&&fm!=m)
            {
            if(nums1[fn]<nums2[fm])
            {
                a[i]=nums1[fn];
                i++,fn++;
            }else{
                a[i]=nums2[fm];
                i++,fm++;
            }
            } 
        }
        if(i%2==0)
            return (a[i/2-1]+a[i/2])/2.0;
        else
            return a[i/2];
    }
};