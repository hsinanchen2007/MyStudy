### 解题思路


### 代码

```java
class Solution {
    public int peakIndexInMountainArray(int[] A) {
        int left=0,right=A.length-1;
        while (left<right){
            int mid=(left+right)/2;
            if (A[mid]>A[mid-1] && A[mid]>A[mid+1])
                return mid;
            if (A[mid]>A[mid-1] && A[mid]<A[mid+1])
                left=mid;
            else
                right=mid;
        }
        return left;
    }
}
```