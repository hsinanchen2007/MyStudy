### 解题思路
三个指针，new_idx表示新的nums1，i表示老的nums1，j表示nums2
i与j比较，谁大，就把谁插入新的nums1中
从右往左插入，这样就可以保证new_idx > i

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0 || nums2.size() == 0) return;
        int new_idx = m+n-1, i = m-1, j = n-1;
        while(new_idx >= 0 && j >= 0 && i >= 0){
            if(nums1[i] >= nums2[j]){
                nums1[new_idx] = nums1[i];
                --new_idx; --i;
            }else{
                nums1[new_idx] = nums2[j];
                --new_idx; --j;
            }
        }
        while(j >= 0){
            nums1[new_idx] = nums2[j];
            --new_idx; --j;
        }
        while(i >= 0){
            nums1[new_idx] = nums1[i];
            --new_idx; --i;
        }
    }

};
```

### 结果
执行用时 : 4 ms , 在所有 C++ 提交中击败了 73.31% 的用户 
内存消耗 : 6.6 MB , 在所有 C++ 提交中击败了 100.00% 的用户