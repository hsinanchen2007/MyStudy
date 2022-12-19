```
class Solution {
    public int distanceBetweenBusStops(int[] distance, int start, int destination) {
        if(start==destination)return 0;
        int low = Math.min(start,destination);
        int high = Math.max(start,destination);
        int result=0,n=distance.length;
        for(int i=low;i<high;i++){
            result+=distance[i];
        }
        int result1=0;
        for(int i=high;i!=low;){
            result1 +=distance[i];
            i=(i+1)%n;
        }
        
        return Math.min(result,result1);
    }
}
```
