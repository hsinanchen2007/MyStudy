### 解题思路
因为有序，所以从最大开始比，加在最后就行，一方加完如果剩的是nums2，全部放nums2前面就完事了。

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int count=m+n-1;
        int i=m,j=n;
        while(i>0&&j>0)
        {
            if(nums2[j-1]>=nums1[i-1]) {nums1[count--]=nums2[j-1];j--;}
            else {nums1[count--]=nums1[i-1];i--;}
        }
        while(j>0)
        {
            nums1[count--]=nums2[j-1];
            j--;
        }
    
    }
};
```