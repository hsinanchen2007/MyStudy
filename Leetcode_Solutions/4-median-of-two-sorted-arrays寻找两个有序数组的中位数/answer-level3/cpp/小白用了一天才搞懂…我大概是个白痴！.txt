### 解题思路


### 代码

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size(),k=(m+n)/2;
        if(m==0)
            return n%2==0?(nums2[k]+nums2[k-1])/2.0:nums2[k];
        if(n==0)
            return m%2==0?(nums1[k]+nums1[k-1])/2.0:nums1[k];
        if(m>n)
            return findMedianSortedArrays(nums2,nums1);
        int left=0,right=m;
        int c1,c2;
        int Lmax1,Lmax2,Rmin1,Rmin2;
        while(left<=right){
            c1=(left+right)/2;
            c2=k-c1;
            Lmax1=(c1==0)?INT_MIN:nums1[c1-1];
            Lmax2=(c2==0)?INT_MIN:nums2[c2-1];
            Rmin1=(c1==m)?INT_MAX:nums1[c1];
            Rmin2=(c2==n)?INT_MAX:nums2[c2];
            if(Lmax1>Rmin2)
                right=c1;
            else if(Lmax2>Rmin1)
                    left=c1+1;
            else break;
        }
        int l=max(Lmax1,Lmax2),r=min(Rmin1,Rmin2);
        return (m+n)%2==0?(l+r)/2.0:max(l,r);
    }
};
```