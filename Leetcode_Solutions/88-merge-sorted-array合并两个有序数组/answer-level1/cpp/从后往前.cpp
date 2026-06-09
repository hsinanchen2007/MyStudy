### 解题思路
准备三个指针，直接在nums1的m+n-1处倒着摆元素，如果nums1的比较大就把nums1的值放到后面，nums2的值大就把nums2的值放到后面，直到nums2的元素放完为止。

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,j=n-1,p=m+n-1;
        while(j>=0){
            if(i>=0){
                if(nums1[i]>=nums2[j])
                    nums1[p--]=nums1[i--];
                else
                    nums1[p--]=nums2[j--];
            }
            else
                nums1[p--]=nums2[j--];
        }      
    }
};
```