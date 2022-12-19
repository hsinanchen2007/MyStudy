### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int peakIndexInMountainArray(int[] A) {
        if(A==null||A.length==0){
            return -1;
        }
        int start=0,end=A.length-1;
        
        while(start<end){
            int mid = (start+end)>>1;
            if(A[mid]>A[mid-1]&&A[mid]>A[mid+1]){
                return mid;
            }
            if(A[mid]>A[mid-1]){
                start=mid;
            }
            if(A[mid]>A[mid+1]){
                end=mid;
            }
        }
        return 0;
    }
}
```