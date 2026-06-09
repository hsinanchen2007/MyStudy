### 解题思路
使用三指针，利用两个数组都是有序的特点。last为m+n-1处开始递减。

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last = m+n-1;
        int p1 = m-1;
        int p2 = n-1;
        while(p1>=0 || p2>=0)
        {
            if(p1>=0&&p2>=0)
            {
                if(nums1[p1]>=nums2[p2])
                {
                    nums1[last] = nums1[p1];
                    p1--;
                }
                else
                {
                    nums1[last] = nums2[p2];
                    p2--;
                }
                last--;
            }
            else if(p1<0)
            {
                nums1[last] = nums2[p2];
                p2--;
                last--;
            }
            else if(p2<0)
            {
                break;
            }
        }
        
    }
};
```