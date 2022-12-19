### 解题思路
此处撰写解题思路
我的思想:
    首先是判断两个数组的长度分别是为空的，只要有一方为空那就直接返回的就是个空的

    如果两个都不为空，那么就两个开始遍历，一个一个都比较，如果相同的话，就将当前的元素和比较的元素都放进新创建的数组中
并且记录下当前的真，遍历完以后，发现不为真的时候直接返回空。
    找到了几个算几个，然后就是把找到的数组进行一次排序，从小到大的位置上排号，排好序以后，又创建了一个比这个排序还要大
一个长度的数组，因为方便找出不一样的数组元素，就再这个最后的面的一个位置上添上了一个-1，就是为了遍历的时候将不同元素放在
一个新的数组中，又因为长度的不一样所以又创建了一个数组，将这个已经放好的数组再次放入这个新的数组中，长度固定好，
只有长度固定好了才不会出现又0 的情况，最后返回最后创建的这个数组,ok;
### 代码

```java
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        int arr[]=new int[nums1.length+nums2.length];
        int qwe[]=new int[0];
        if(nums2.length==0 && nums1.length==0){
            return qwe;
        }else if(nums1.length==0 && nums2.length!=0){
            return qwe;
        }else if(nums1.length!=0 && nums2.length==0){
            return qwe;
        }
    int p=0;
    boolean flag=false;
        for(int i=0;i<nums1.length;i++){
            for(int j=0;j<nums2.length;j++){
                if(nums1[i]==nums2[j]){
                    arr[p]=nums1[i];
                    arr[p+1]=nums2[j];
                    p++;
                    flag=true;
                }
            }
        }
        if(!flag){
            return qwe;
        }
        p++;
        for(int i=0;i<p-1;i++){
            for(int j=i+1;j<p;j++){
                if(arr[i]>arr[j]){
                    int t=arr[i];
                    arr[i]=arr[j];
                    arr[j]=t;
                }
            }
        }
        int k=0;
        int c[]=new int[p+1];
        c[p]=-1;
        for(int i=0;i<p;i++){
               c[k]=arr[i];
               k++;
        }
        int d[]=new int[k];
        int m=0;
        for(int i=0;i<k;i++){
            if(c[i]!=c[i+1]){
                d[m]=c[i];
                m++;
            }
        }
        int e[]=new int[m];
        int pp=0;
        for(int i=0;i<m;i++){
            e[pp]=d[i];
            pp++;
        }

        
        return e;
    }
}
```