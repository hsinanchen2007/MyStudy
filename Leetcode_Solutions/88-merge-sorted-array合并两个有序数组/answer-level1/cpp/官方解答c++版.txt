### 解题思路
官方解答c++版

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        
        m--;
        n--;
        int i=m+n+1;
        while(m>=0&&n>=0)
        {
            
            if(nums1[m]>=nums2[n])
            {
                nums1[i]=nums1[m];
                m--;
            }
            else
            {
                nums1[i]=nums2[n];
                n--;
            }
            i--;
        }
        //如果nums2中有剩余，则将剩余部分复制到nums1
        if(m<0)
        {
            while(n>=0)
            {
                nums1[n]=nums2[n];
                n--;
            }
        }

    }
};
```