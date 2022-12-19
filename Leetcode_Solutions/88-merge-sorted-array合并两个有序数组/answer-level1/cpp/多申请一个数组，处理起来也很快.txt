### 解题思路
见注释

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(nums2.empty()) return;

        vector<int> ret; //题目没有要求原地合并， 新申请一个数组， 直接存放即可， 如果不通过再做处理
        int i=0, j=0, k=0; //i为合并后的数组的游标， j为nums1的游标， j<m,  k为nums2的游标， k<n
        while(i<m+n){
            if(j<m && k<n){
                if(nums1[j] < nums2[k]) {
                    ret.push_back(nums1[j]);
                    j++;
                } else {
                    ret.push_back(nums2[k]);
                    k++;
                }
            } else if(j>=m){
                ret.push_back(nums2[k]);
                k++;
            } else if(k>=n){
                ret.push_back(nums1[j]);
                j++;
            }
            i++;
        }

        for(int i=0; i<ret.size(); i++){
            nums1[i] = ret[i];
        }
        return;
    }
};
```