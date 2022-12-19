首先一定要注意审题，审题明白了会给自己降难度的，1.nums1的空间是足够的，但不管空间多大，能用到的空间大小只有n+m，2.原始的两个数组都是有序的！！！
```
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int a=m-1;
        int b=n-1;
        int c=m+n-1;
        while(b>=0&&a>=0)
        {
          if(nums2[b]>nums1[a])
          {
            nums1[c]=nums2[b];
            b--;
            c--;
          } 
          else{
              nums1[c]=nums1[a];
              a--;
              c--;
          }         
        }
        while(b>=0)
        {
            nums1[c]=nums2[b];
            c--;
            b--;
        }
    }
};
```
