### 解题思路
双指针 从后往前填充数组

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        if(n < 1)
        {
            return;
        }

        int s = m+n-1;
        int i = n-1;
        int j = m-1;
        while(i>=0)
        {
            if(j < 0)
            {
                // 因为这里是要将结果存放在nums1中，所以此时若nums2未完成比较，则直接填充到
                // nums1的前面
                nums1[s] = nums2[i];
                --i;
                --s;
                continue;
            }
            if(nums1[j] < nums2[i])
            {
                nums1[s] = nums2[i];
                --i;
                --s;
            }else
            {
                nums1[s] = nums1[j];
                --j;
                --s;
            }
        }
    }
};
```