### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            while(n!=0&&m!=0){
                if(nums1[m-1]>=nums2[n-1]){
                    nums1[n+m-1]= nums1[m-1];
                    m--;
                }else{
                    nums1[n+m-1]= nums2[n-1];
                    n--;
                }
                
            }
            while(n>0){
                nums1[n-1]=nums2[n-1];
                n--;
            }
    }
};
```