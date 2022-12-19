### 解题思路
暴力

### 代码

```java
class Solution {
    public List<Integer> luckyNumbers (int[][] matrix) {
       List<Integer> list = new ArrayList<>();

        int shuZhe = matrix.length;
        int hengZhe = matrix[0].length;
        
        for (int i=0;i<shuZhe;i++){
            int min = 100000;
            int index = 0;
            for (int j=0;j<hengZhe;j++){
                if(min > matrix[i][j]){
                    min = matrix[i][j];
                    index = j;
                }
            }

            int k=0;
            for (;k<shuZhe;k++){
                if (min < matrix[k][index]){
                    break;
                }
            }
            
            if (k == shuZhe){
                list.add(matrix[i][index]);
            }
        }
        return list;
    }
}
```