方法一 合并后排序
```
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m,j=0;i<m+n;i++,j++) nums1[i]=nums2[j];
        sort(nums1.begin(),nums1.end());
    }
```
方法二 双指针1 从前到后
```
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p=0,i=0,j=0;
        vector<int> tmp(nums1.begin(),nums1.begin()+m);
        while(i<m&&j<n) nums1[p++] = (tmp[i] < nums2[j]) ? tmp[i++] : nums2[j++];
        while(j<n) nums1[p++] = nums2[j++];
        while(i<m) nums1[p++] = tmp[i++];
    }
```
方法三 双指针2 从后到前
```
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1=m-1,p2=n-1,p=m+n-1;
        while(p1>=0&&p2>=0){
            nums1[p--]=nums1[p1]>nums2[p2]? nums1[p1--]:nums2[p2--];
        }
        if(p1<0){
             while (p2 >= 0)
                nums1[p--] = nums2[p2--];
        }
    }
};
```
