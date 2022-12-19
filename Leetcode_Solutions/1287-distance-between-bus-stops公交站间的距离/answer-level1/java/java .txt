```
class Solution {
    public int distanceBetweenBusStops(int[] distance, int start, int destination) {
        int forward = 0;
        int backward = 0;
        //start>destination
        int begin = Math.min(start,destination);
        int end = Math.max(start,destination);
        for(int i = 0;i<distance.length;i++){
            if(i>=begin&&i<end){
                forward += distance[i];
            }else{
                backward += distance[i];
            }
            
        }        
        return Math.min(forward,backward);
    }
}
```
