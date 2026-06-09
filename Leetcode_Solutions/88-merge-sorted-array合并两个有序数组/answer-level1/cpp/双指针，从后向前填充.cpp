### 解题思路
与字符串中遇到空格然后填充某字符串类似。设置双指针，从后向前遍历。

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        while(i>=0&j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k] = nums1[i];
                i--;
            }
            else{
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        if(j>=0){while(j>=0){nums1[k]=nums2[j];k--;j--;}}
    }
};
```