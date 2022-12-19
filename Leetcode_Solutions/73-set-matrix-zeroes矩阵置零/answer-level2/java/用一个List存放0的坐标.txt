```
class Solution {
    public void setZeroes(int[][] matrix) {
        List<Integer> list=new ArrayList<>();
        if(matrix.length==0||matrix[0].length==0) return;
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                if(matrix[i][j]==0){
                    list.add(i);
                    list.add(j);
                } 
            }
        }
       if(list.size()!=0){
           int size=list.size()/2; 
           for(int i=0;i<size;i++){
                set(matrix,list);
            }   
       }
        
    }
    
    public void set(int[][] matrix,List<Integer> list) {
        int x=list.remove(0);
        int y=list.remove(0);
         for(int i=0;i<matrix.length;i++){
            matrix[i][y]=0;
         }
         for(int i=0;i<matrix[0].length;i++){
               matrix[x][i]=0;
         }
    }
}
```
