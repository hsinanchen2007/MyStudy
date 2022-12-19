```
class Solution {
public:
    void merge(vector<int>& nums1,int i,vector<int>& nums2,int j,int cnt)
    {
        if(i==-1)
        {
            for(int k=j;k>=0;k--) nums1[k]=nums2[k];
            return;
        }
        if(j==-1) return;
        if(nums1[i]<nums2[j])
        {
            nums1[cnt]=nums2[j];
            merge(nums1,i,nums2,j-1,cnt-1);
        }
        else
        {
            nums1[cnt]=nums1[i];
            merge(nums1,i-1,nums2,j,cnt-1);
        }
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int cnt=m+n-1;
        merge(nums1,m-1,nums2,n-1,cnt);
    }
};
```
好像必须构造一个新函数才行