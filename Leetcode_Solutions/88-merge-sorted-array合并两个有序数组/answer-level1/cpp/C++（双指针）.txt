### 解题思路
此处撰写解题思路
1、首先来考虑两种特殊情况：
（1）nums1内的有效长度为0，直接将nums2复制到nums1即可；
（2）nums2内的有效长度为0；不做任何事情；
2、利用双指针
### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
       if(n == 0) return;
        if(m == 0)
        {
            for(int i = 0; i < n; i++)
            nums1[i] = nums2[i];
            return;
        }
       int j = 0; //nums2的指针
       for(int i = 0; i < m+n; i++) //i为nums1的指针
       {
           while(nums2[j] <= nums1[i])
           {
               for(int k = m+j; k > i; k--)
               {
                   nums1[k] = nums1[k-1];
               }
               nums1[i] = nums2[j];
               j++;
               break;
           }
           if(j == n) break; //nums1中最大值比nums2中最大值大
       }

       if(j <= n-1) //nums1中最大值比nums2中最大值小
       {
           for(int t = m+j; t < m+n; t++)
           {
               nums1[t] = nums2[j];
               j++;
           }
       }
    }
};
```