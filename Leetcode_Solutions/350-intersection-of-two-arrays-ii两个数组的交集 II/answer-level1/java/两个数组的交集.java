### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
      int []sum=new int[nums1.length];
      Arrays.sort(nums1);
      Arrays.sort(nums2);  
      int i=0,j=0,x=0;
      while(i<nums1.length&&j<nums2.length){
          if(nums1[i]==nums2[j]){
              sum[x++]=nums1[i];
              i++;
              j++;
          }
          else if(nums1[i]>nums2[j])
          j++;
          else i++;
      }
      
      int []num=new int[x];
      for(int k=0;k<x;k++)
      num[k]=sum[k];
      return num;
    }
}
```