从尾部更新序列1，双指针遍历，更大的元素插入新序列的尾部
```
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0) return;
        int p = m+n-1; m--; n--;
        while(p>=0 && m>=0 && n>=0){
            nums1[p--] = (nums1[m] >= nums2[n])? nums1[m--]:nums2[n--];
        }
        while(p>=0 && m>=0) {nums1[p--] = nums1[m--];}
        while(p>=0 && n>=0) {nums1[p--] = nums2[n--];}
    }
};
```
