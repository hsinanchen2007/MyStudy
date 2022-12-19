```
class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        Queue <Integer> q = new LinkedList<>();
        int sum;
        boolean find=false;
        int a=gas.length;
        for(int i=0;i<a;i++){
            if(gas[i]>=cost[i]){
                q.add(i);// can start from i;
            }
        }
        while(!q.isEmpty()){
            sum=0;
            int b=q.poll();//start from b
            int j=b;
           // if(q.size()==1) return q.poll();
            for(int k=0;k<a;k++){
                sum=sum+gas[j%a]-cost[j%a];
                if(sum>=0){
                    j=j+1;
                    find=true;
                }
                else {
                    find =false;
                    break;
                }    
            }
            if(find==true)
            return b;
        }
        return -1;
    }
}
```
