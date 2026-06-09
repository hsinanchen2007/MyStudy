### 解题思路
归并最后一次排序，两个有序数组

### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m=nums1.length;
        int n=nums2.length;
        int[] newArr = new int[m+n];
        int i=0;
        int j=0;
        int index=0;
        //归并两个有序数组
        while(i<m&&j<n){
            if(nums1[i]<nums2[j]){
                newArr[index]=nums1[i];
                i++;
            }else{
                newArr[index]=nums2[j];
                j++;
            }
            index++;
        }
        //处理多余元素
        while(i<m){
            newArr[index]=nums1[i];
            i++;
            index++;
        }
         while(j<n){
            newArr[index]=nums2[j];
            j++;
            index++;
        }
        float t=0;
        if((m+n)%2==1){
           t=(float)newArr[(m+n)/2];
        }
        if((m+n)%2==0){
            t=(float)(newArr[(m+n)/2-1]+newArr[(m+n)/2])/2;
        }
        return t;
    }
}
```