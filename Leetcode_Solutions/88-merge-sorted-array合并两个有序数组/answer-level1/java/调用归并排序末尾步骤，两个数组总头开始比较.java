### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
    int p1 = 0;
    int p2 = 0;
    int p = 0;
    int[] rev = new int[m+n];	
    //m个数末尾为nums1[m-1]    
    while(p1 < m && p2 < n)
    {
        if(nums1[p1] <= nums2[p2])
            rev[p++] = nums1[p1++];
        else
            rev[p++] = nums2[p2++];
    }    
    while(p1 < m)
    {
        rev[p++] = nums1[p1++];
    }
    while(p2 < n)
    {
        rev[p++] = nums2[p2++];
    }
    
    for(int i = 0;i< m+n;i++)
    {
        nums1[i] = rev[i];
    }   
   
    }
}
```