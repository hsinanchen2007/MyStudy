执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户  
内存消耗 :42.7 MB, 在所有 Java 提交中击败了47.70%的用户  
```
class Solution {
    public int peakIndexInMountainArray(int[] A) {
        int low = 0;
        int high = A.length-1;
        while(low<=high) {
            int mid = low+(high-low)/2;
            // if(mid<=0||mid>=A.length-1) {
            //     return -1;
            // }
            if(A[mid]>A[mid-1]&&A[mid]>A[mid+1]) {
                return mid;
            }
            if(A[mid]>A[mid-1]&&A[mid]<A[mid+1]) {
                low=mid+1;
            }
            if(A[mid]<A[mid-1]&&A[mid]>A[mid+1]) {
                high=mid-1;
            }
        }
        return -1;
    }
}
```
感谢@Uneed提出的测试用例[3,5,3,2,0]，这个用例上边的代码会越界，抱歉没有考虑清楚。  
更新代码如下  
执行用时 :1 ms, 在所有 Java 提交中击败了88.80%的用户  
内存消耗 ：37.6 MB, 在所有 Java 提交中击败了95.64%的用户  
```
class Solution {
    public int peakIndexInMountainArray(int[] A) {
        int low = 0;
        int high = A.length-1;
        while(low<high) {
            int mid = low+(high-low)/2;
            if(A[mid]>A[mid-1]&&A[mid]>A[mid+1]) {
                return mid;
            }
            if(A[mid]>A[mid-1]&&A[mid]<A[mid+1]) {
                low=mid;
            }
            if(A[mid]<A[mid-1]&&A[mid]>A[mid+1]) {
                high=mid;
            }
        }
        return -1;
    }
}
```