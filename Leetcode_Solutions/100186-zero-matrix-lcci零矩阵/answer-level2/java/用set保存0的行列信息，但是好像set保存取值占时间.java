```
class Solution {
    public void setZeroes(int[][] matrix) {
        //行
        Set<Integer> a = new HashSet<>();
        //列
        Set<Integer> b = new HashSet<>();
        for (int i = 0 ;i< matrix.length;i++){
            for (int j = 0 ; j<matrix[0].length;j++){
                if(matrix[i][j] == 0){
                    a.add(i);
                    b.add(j);
                }
            }
        }
        Iterator<Integer> aIterator = a.iterator();
        Iterator<Integer> bIterator = b.iterator();

        while (aIterator.hasNext()){
            //得放在外面，在for里面会一直next
            int temp = aIterator.next();
            for (int i = 0 ;i<matrix[0].length;i++){
                matrix[temp][i] =0;
            }
        }
        while (bIterator.hasNext()){
            int temp = bIterator.next();
            for (int i = 0 ;i<matrix.length;i++){
                matrix[i][ temp] =0;
            }
        }

    }
}
```
