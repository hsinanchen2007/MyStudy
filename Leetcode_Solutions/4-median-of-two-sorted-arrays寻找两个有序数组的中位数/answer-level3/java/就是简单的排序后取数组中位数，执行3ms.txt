### 解题思路
首先在最下面写一个取数组的中位数的方法，取中位数如果是奇数就很简单的拿出来就行，偶数就计算一下，注意Java double类型的计算数值。
首先我们对特殊情况做出判断，就是分别有一个数组为空的情况，那么对另一个不为空的数组直接动用我们的取数组
中位数的方法即可。
当都不为空的时候，将这两个数组合并。
合并思路：
在两个数组里，分别以数组长度为界，i为nums1的，j为nums2的。
从数组首位开始比较合并，小的放前面，并把此时相应的i或者j自增1；
当我们在其中某个达到它所在的数组的长度的时候，我们就只要拼接另一个数组的后面部分即可；
例如：nums1 {1,3,5}  nums2{2,4,6,8,10}
i=3,j=5;
当i=3,j=2的时候
i到了nums1数组的界限值，我们的拼接数组此时是{1,2,3,4,5}
只要再拼接nums2的 6，8，10即可
拼接完成后取中位数就可以达到题目要求了
### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        if (nums1.length==0){
            return getMiddle(nums2);
        }
        if (nums2.length==0){
            return getMiddle(nums1);
        }
        int []c=new int[nums1.length+nums2.length];
       outer: for (int i=0,j=0;i<nums1.length&&j<nums2.length;){
            if (nums1[i]<nums2[j]){
                c[i+j]=nums1[i];
                i++;
            }
            else{
                c[i+j]=nums2[j];
                j++;
            }
            if (i==nums1.length&&j!=nums2.length){
                for (int x=i+j;x<nums1.length+nums2.length;){
                    c[x]=nums2[j];
                    j++;
                    x++;
                }
                break outer;
            }
            if (i!=nums1.length&&j==nums2.length){
                for (int x=i+j;x<nums1.length+nums2.length;){
                    c[x]=nums1[i];
                    i++;
                    x++;
                }
                break outer;
            }
        }
        return getMiddle(c);
    }
    public  double  getMiddle(int num[]){
        double middle;
        if ((num.length%2)==0){
            middle=(num[(num.length - 1) / 2]+num[(num.length + 1) / 2])/2.0;
        }
        else {
            middle = num[(num.length - 1) / 2];
        }
        return middle;
    }
}
```