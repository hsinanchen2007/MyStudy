```
class Solution {
    public int peakIndexInMountainArray(int[] A) {
       
        int i=1;
        //找山脚
        while(A[i-1]>A[i] && i!=A.length){
            i++;
        }
        //向上爬
        while(A[i-1]<A[i] && i!=A.length){
            i++;
        }
        
        return i-1;
    }
}
```
