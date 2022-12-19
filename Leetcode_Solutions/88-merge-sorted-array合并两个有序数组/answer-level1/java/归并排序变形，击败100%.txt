### 解题思路
可以将此题看成归并排序的变形，即将nums1[0....m-1]与nums2[m.....m+n-1]进行归并
首先将这两个数组复制到一个数组中，然后利用三指针，不断地进行比较

### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        
        int mid=m-1;
        int i=0,r=m+n-1;
        int j=m;
        int[] copy=new int[m+n];
        System.arraycopy(nums1,0,copy,0,m);
        System.arraycopy(nums2,0,copy,m,n);
        for(int k=0;k<=r;k++){
            if(i>mid){
                nums1[k]=copy[j];
                j++;

            }
            else if(j>r){
                nums1[k]=copy[i];
                i++;

            }else if(copy[i]<copy[j]){
                nums1[k]=copy[i];
                i++;

            }
            else{
                nums1[k]=copy[j];
                j++;
            }

        }
        
    }
}
```