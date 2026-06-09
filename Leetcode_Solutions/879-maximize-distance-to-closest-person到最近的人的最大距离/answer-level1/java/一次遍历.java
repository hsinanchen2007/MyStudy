```
class Solution {
    public int maxDistToClosest(int[] seats) {
        int max = 0;
        int num = 0;
        boolean first = true;
        for(int i=0;i<seats.length;i++){
            if(seats[i] == 0){
                num++;
            }
            if(seats[i] ==1){
                if(first){
                    max = num; 
                    first = false;
                }else{
                    max = max > (num+1)/2 ?max:(num+1)/2;
                }                
                num =0;               
            }

            if(i == seats.length-1 ){
                max = max>num ? max : num;
            }
        }
        return max;
    }
}
```
