```
class Solution {
    public int numEquivDominoPairs(int[][] dominoes) {
        int[][] count = new int[10][10];
        int sum = 0;
         int a=0,b=0;
        for(int[] e: dominoes){
            if(e[0]>e[1]){
                a = e[1];
                b = e[0];
            }
            else{
                a = e[0];
                b = e[1];
            }
            sum+=count[a][b];
            count[a][b]+=1;
        }
        return sum;
    }
}
```
