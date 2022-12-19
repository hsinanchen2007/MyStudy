### 解题思路
此处撰写解题思路
   ①定义一个新数组nums，两个指向nums1和nums2的指针i,j
   ②因为两个数组是有序数组，所以就直接进行比较，小的数组更新到nums上 并更新nums和对应的nums1/2的数组指针
   ③其次讨论没有更新完毕的数组 将其全部加入nums即可
## 基础错误点：
   int[] nums=new int[length];
   int[] nums=new int[]{1,2}
 
   对于有序数组找中位数，直接用偶/2  (奇+1)/2
   对于无序数组找中位数则将其变为有序，无序数组利用冒泡排序，快速排序等变为有序数组
### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] nums =new int[nums1.length+nums2.length];
        int i=0,j=0,m=0;
        while(i<nums1.length && j<nums2.length){
            if(nums1[i]>nums2[j]){//都不为空
                nums[m]=nums2[j];
                j++;
            }else{
                nums[m]=nums1[i];
                i++;
            }
            m++;
        }
        
        while(i<nums1.length){//nums1 有剩余
                nums[m]=nums1[i];
                m++;i++;
            }
        while(j<nums2.length){//nums2 有剩余
                nums[m]=nums2[j];
                m++;j++;
            }
        return findMedian(nums);
    }
    public double findMedian(int[] nums){//找有序数组中位数
    double median=0,result=0;
    if((nums.length-1)%2==0){//是偶数 0 1 2
    return nums[(nums.length-1)/2];
    }else{//奇数 0 1 2 3
      result=nums[(nums.length-1)/2]+nums[(nums.length-1)/2+1];
       median=result/2;
       return median;
    }
}
}
```