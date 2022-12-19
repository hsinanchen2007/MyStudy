### 解题思路
直接归并排序（本题属于归并排序中的后一部分）

### 代码

```cpp
class Solution {//直接归并排序
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0,j =0,k = 0;
        int d[m+n];
        while(i<m && j<n)
        {
            if(nums1[i] <nums2[j]) d[k++] = nums1[i++];
            else d[k++] = nums2[j++];
        }
        while(i<m) d[k++] = nums1[i++];
        while(j<n) d[k++] = nums2[j++];
        for(int c = 0;c<m+n;c++)
        {
            nums1[c] = d[c];
        }
    }
};
```