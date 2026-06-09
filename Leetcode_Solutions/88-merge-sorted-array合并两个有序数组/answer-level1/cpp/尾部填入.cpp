```
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int lenth = m + n;
        while(m+n)
        {
            if(0 == m)
                nums1[--lenth] = nums2[--n];
            else if(0 == n)
                nums1[--lenth] = nums1[--m];
            else
            {
                nums1[--lenth] = (nums1[m-1]>nums2[n-1])? nums1[--m]:nums2[--n];       
            }
        }
    }
};
```
