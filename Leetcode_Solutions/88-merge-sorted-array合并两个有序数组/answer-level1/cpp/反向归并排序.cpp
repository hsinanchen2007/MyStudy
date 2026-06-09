### 解题思路
C++;   思路是反向的归并排序，两个数组从最后开始向前比较，大的数放在nums1的后面

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {


        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        while(k >= 0){
            if(i < 0 )
                nums1[k--] = nums2[j--];
            else if(j < 0)
                nums1[k--] = nums1[i--];
            else if(nums1[i] >= nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }




    }
};
```