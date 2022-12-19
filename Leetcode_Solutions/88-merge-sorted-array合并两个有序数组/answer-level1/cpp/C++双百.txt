### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/14f51ded4d1d105249429c8f09d3af0e80c73c489200827ae294a8a6b80634ab-image.png)

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len1 = m-1, len2 = n-1;
        int len = m+n-1;
        while(len1>=0 && len2>=0){
            nums1[len--] = nums1[len1]>nums2[len2]?nums1[len1--]:nums2[len2--];
        }
        while(len2>=0){
            nums1[len--] = nums2[len2--];
        }
    }
};
```