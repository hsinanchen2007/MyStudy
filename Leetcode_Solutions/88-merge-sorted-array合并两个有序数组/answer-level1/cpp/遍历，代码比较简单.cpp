### 解题思路
此处撰写解题思路
把num2的元素补到num1后面，sort一下
### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m,j=0; i<m+n,j<n; ++i,++j){
            nums1[i]=nums2[j];
        }
        sort(nums1.begin(),nums1.end());
    }
};
```