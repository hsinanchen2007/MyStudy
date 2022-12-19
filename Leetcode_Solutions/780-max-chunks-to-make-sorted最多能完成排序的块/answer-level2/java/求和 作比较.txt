```
class Solution {
    public int maxChunksToSorted(int[] arr) {
        int res=0,sum1=0,sum2=0;
        for(int i=0;i<arr.length;i++){
            sum1+=i;
            sum2+=arr[i];
            if(sum1==sum2) res++;
        }
        return res;
    }
}
```
