### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = m + n - 1;
        for(int k = n - 1; k >= 0; k--){
            while(i >= 0 && nums1[i] >= nums2[k]){  //逻辑与前后不能调换，当判断完第一个不符合条件之后后面不会去判断，可能会导致越界的情况。
                 nums1[j--] = nums1[i--];  
            }
                 nums1[j--] = nums2[k];
        }
    }
};
```