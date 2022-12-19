### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m==0) {nums1 = nums2; return;}
        int p1(m-1), p2(n-1);  
        int all(m+n-1);
        while(p1>=0 && p2>=0){
            if(nums1[p1] >= nums2[p2]) {
                nums1[all] = nums1[p1];
                all--;
                p1--;
            }
            else{
                nums1[all] = nums2[p2];
                all--;
                p2--;
            }
        }
        while(p2 >=0){
            nums1[p2] = nums2[p2];
            p2--;
        }
        return;    
    }
};
```