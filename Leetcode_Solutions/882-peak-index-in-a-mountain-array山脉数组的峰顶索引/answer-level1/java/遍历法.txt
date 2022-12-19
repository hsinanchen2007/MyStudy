```
public int peakIndexInMountainArray(int[] A) {
        int slow=0;
        int fast=1;
        int index=0;
        while(A[slow]<A[fast]){
            slow++;
            fast++;
            if(A[slow]>A[fast]){
                index=slow;
                break;
            }
        }
        return index;
    }
```
