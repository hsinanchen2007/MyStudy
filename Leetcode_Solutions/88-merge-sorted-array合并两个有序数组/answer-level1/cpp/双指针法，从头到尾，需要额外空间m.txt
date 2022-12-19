### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int* temp_nums1 = new int[m];
        for(int i = 0;i<m;i++){
            temp_nums1[i] = nums1[i];
        }
        int k=0;  //nums1
        int k1=0; //temp_nums1
        int k2=0; //nums2
        while(k1<m && k2<n){
            nums1[k++] = (temp_nums1[k1]<=nums2[k2]?temp_nums1[k1++]:nums2[k2++]);
        }
        while(k1<m){
            nums1[k++] = temp_nums1[k1++];
        }
        while(k2<n){
            nums1[k++] = nums2[k2++];
        }
    }
};
```