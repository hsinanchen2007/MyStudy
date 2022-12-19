### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m -1, j = n - 1, k = m + n -1;
        while(i >= 0 && j >= 0){
            nums1[k--] = (nums1[i] < nums2[j]) ? nums2[j--] : nums1[i--];
        }
        if(j >= 0){
            while(j >= 0){
                nums1[k--] = nums2[j--];
            }
        }
    }
};
```