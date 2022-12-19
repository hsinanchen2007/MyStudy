### 解题思路
本题属于在一个有序序列中查找第一个满足某条件的数，返回其下标。该条件为，大于它的下一个元素，第一个满足该条件的数即山峰。

### 代码

```java
class Solution {
    public int peakIndexInMountainArray(int[] A) {
        int lo=0,hi=A.length-1;
        while(lo<hi)
        {
            int mid=lo+(hi-lo)/2;
            if(A[mid]>A[mid+1]) hi=mid;
            else                lo=mid+1;
        }
        return lo;
    }
}
```