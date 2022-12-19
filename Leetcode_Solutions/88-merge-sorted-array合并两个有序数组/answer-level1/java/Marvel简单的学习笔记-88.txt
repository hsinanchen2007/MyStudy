### 双指针--从前往后
本题考察的就是最基本的归并排序的思想，熟练写出归并排序的merge()方法即可，这种方法属于双指针从前往后扫描。
时间复杂度：O(n)。线性级别的时间复杂度，需要遍历两个数组，n为两个数组长的之和。
空间复杂度：O(n)。需要辅助数组，辅助数组的长度等于所有元素的个数，故也是线性级别。

### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int[] aux=new int[nums1.length];
        int i=0,j=0;
        for(int k=0;k<aux.length;k++)
        {
            if      (i==m)              aux[k]=nums2[j++];
            else if (j==n)              aux[k]=nums1[i++];
            else if (nums1[i]<nums2[j]) aux[k]=nums1[i++];
            else                        aux[k]=nums2[j++];
        }
        for(int k=0;k<aux.length;k++)
            nums1[k]=aux[k];
    }
}
```
### 双指针--从后往前
双指针除了从前往后以外，还可以从后往前得到改进。由于题目中的nums1[]数组长度足够放下所有元素，故思考一种不需要额外数字空间的改进，即双指针从后往前。定义两个指针i、j，i指向第一个数组最后一个有效元素，j指向第二个数组最后一个有效元素，从整个数组nums1[]最后一个位置开始，比较i、j指向的元素，优先使用更大的放到nums1[k]的位置。如此这般，不断地往前填充nums1[]数组。同上种方法一样，当i扫描完后，使用j指向的元素来填充；同理，当j扫描完后，使用i指向的元素来填充。直到整个数组填充完即完成了合并。
时间复杂度：O(n)。n为所有元素之和。
空间复杂度：O(1)。不需要额外数组空间了，只需int指针即可。

### 代码
```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int i=m-1,j=n-1;
        for(int k=m+n-1;k>=0;k--)
        {
            if     (i<0)                nums1[k]=nums2[j--];
            else if(j<0)                nums1[k]=nums1[i--];
            else if(nums1[i]>nums2[j])  nums1[k]=nums1[i--];
            else                        nums1[k]=nums2[j--];
        }
    }
}
```