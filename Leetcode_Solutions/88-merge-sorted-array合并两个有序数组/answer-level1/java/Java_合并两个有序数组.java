### 解题思路
首先把nums1中的数组复制到另一个新建的数组nums中
比较新建的数组与nums2中数字的大小，将较小的数字依次存入nums1中
注：nums1即为结果

### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int[]nums=new int[m];
        for(int k=0;k<m;k++){
            nums[k]=nums1[k];
        }
        int i=0,j=0,p=0;
        while(i<m&&j<n){
            if(nums[i]<=nums2[j]){
                nums1[p++]=nums[i++];
            } else {
                nums1[p++]=nums2[j++];
            }
        }
        while(i<m){
            nums1[p++]=nums[i++];
        }
        while(j<n){
            nums1[p++]=nums2[j++];
        }
    }
}
```