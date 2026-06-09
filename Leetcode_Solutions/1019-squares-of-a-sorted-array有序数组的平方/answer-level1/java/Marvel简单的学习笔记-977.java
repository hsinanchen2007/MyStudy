### 解题思路
采用归并排序中**归并**过程的思想，即**将两个有序数组归并为一个有序数组**。但本题从何得到两个有序数组呢？
由于给定数组是升序的，故可以分为两个区域，一个只含负数，另一个区域只含非负数。然后，非负数区域的顺序即平方后的顺序；负数区域的顺序是平方后的降序。至此得到两个有序数组，可以归并。
定义两个指针i、j，分别指向负数区域的末尾，非负数区域的开头，i从后往前扫描，j从前往后扫描，执行归并排序的归并过程即可将两个有序数组归并为一个有序数组。
用二分查找确定指针j的位置，即非负数区域的开头。同时，i=j-1。
时间复杂度：O(n)。扫描了整个数组。
空间复杂度：O(n)。非原地排序，需要额外数组空间，辅助数组大小即原数组大小。

### 代码

```java
class Solution {
    private int binarySearch(int[] a) {
        int lo=0,hi=a.length;
        while(lo<hi)
        {
            int mid=lo+(hi-lo)/2;
            if(a[mid]>=0)   hi=mid;
            else            lo=mid+1;
        }
        return lo;
    }
    public int[] sortedSquares(int[] A) {
        int j=binarySearch(A);
        int i=j-1;
        int[] output=new int[A.length];
        for(int k=0;k<output.length;k++)
        {
            if(i<0)
            {
                output[k]=A[j]*A[j];
                j++;
            }
            else if(j>A.length-1)
            {
                output[k]=A[i]*A[i];
                i--;
            }
            else if(A[i]*A[i]<A[j]*A[j])
            {
                output[k]=A[i]*A[i];
                i--;
            }
            else
            {
                output[k]=A[j]*A[j];
                j++;
            }
        }
        return output;
    }
}
```