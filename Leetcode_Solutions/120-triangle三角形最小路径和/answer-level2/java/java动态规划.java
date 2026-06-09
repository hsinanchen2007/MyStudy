```
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int shabi[][]=new int[triangle.size()][triangle.size()];
        for(int i=0;i<triangle.size();i++){
            for(int j=0;j<triangle.get(i).size();j++){
                if(i==0){
                    shabi[i][j]=triangle.get(0).get(0);
                    continue;
                }
                else if(j==0){
                    shabi[i][j]=shabi[i-1][0]+triangle.get(i).get(j);
                }
                else if(j==triangle.get(i).size()-1){
                    shabi[i][j]=shabi[i-1][j-1]+triangle.get(i).get(j);
                }
                else{
                    shabi[i][j]=Math.min(shabi[i-1][j-1],shabi[i-1][j])+triangle.get(i).get(j);
                }
            }
        }
        int min=Integer.MAX_VALUE;
       for(int i=0;i<triangle.get(triangle.size()-1).size();i++){
           if(shabi[triangle.size()-1][i]<min)
               min=shabi[triangle.size()-1][i];
       }
        return min;
    }
}
```
