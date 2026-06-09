### 解题思路
此处撰写解题思路
我的思路:
    先创建一个能够装的下两个原始数组长度的数组！
    再将两个数组进行和并成一个新的数组；
    合并以后再判断当前这个新的数组的长度是否是奇数还是偶数的
如果是偶数的，那么直接找到新数组的长度除2-1的这个下标，和新数组的长度除2的这个下标，将这两个数相加以后除2
得到的就是一个中位数。
如果是奇数，那么直接找到新数组的长度除2的这个下标，返回就可以了；
最后返回值;ok;
### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int arr[]=new int[nums1.length+nums2.length];
        int len=0;
        for(int i=0;i<nums1.length;i++){
            arr[i]=nums1[i];
            len++;
        }
        int j=0;
        for(int i=0;i<nums2.length;i++){
            arr[len]=nums2[i];
            len++;
        }

       for(int i=0;i<arr.length;i++)
       {
           for(int k=i+1;k<arr.length;k++){
               if(arr[i]>arr[k]){
                   int t=arr[i];
                   arr[i]=arr[k];
                   arr[k]=t;
               }
           }
       }
       double sum=0.0;
        if(arr.length%2!=0)
           sum=(arr[arr.length/2]);
        else{
            double a=arr[arr.length/2-1];
            double b=arr[(arr.length/2)];
            sum=(b+a)/2.0;
        }
        return sum;
    }
}
```