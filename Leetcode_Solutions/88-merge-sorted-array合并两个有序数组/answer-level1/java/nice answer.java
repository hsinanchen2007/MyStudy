### 解题思路
此处撰写解题思路
用一个i=m+n-1做新的nums1数组的最后一个元素索引 从后往前 遍历nums1 nums2数组 给到新的nums1数组即可
### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        for(int i=m+n-1;i>=0;i--){
        if(m>0&&n>0&&nums1[m-1]>nums2[n-1]||n==0){
            nums1[i]=nums1[--m]; // 新的nums1是反转的 大小反过来的
        }else{
            nums1[i]=nums2[--n];  //否则新的nums1的元素是nums2的反转元素
        }

        }
    }
}
```