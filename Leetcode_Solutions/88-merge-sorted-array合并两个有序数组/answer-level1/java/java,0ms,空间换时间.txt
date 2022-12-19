### 解题思路
另找个数组copy一下2就行

### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int r1=0,r2=0;//两个指针分别指向两个数组的头
        int[] ans=new int[m+n];
        int i=0;
        while(r1<m&&r2<n)
        {
            if(nums1[r1]<nums2[r2])
                 ans[i++]=nums1[r1++];
             else 
                 ans[i++]=nums2[r2++];                       
        }
        while(r1<m)
         ans[i++]=nums1[r1++];
        while(r2<n)
         ans[i++]=nums2[r2++];
        for(int j=0;j<m+n;j++)
         nums1[j]=ans[j];
    }
}
```