### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<Integer> luckyNumbers (int[][] matrix) {
        List<Integer> list = new ArrayList<>();
        int min[] = new int[50];
        int max[] = new int[50];
        Arrays.fill(min,Integer.MAX_VALUE);
        Arrays.fill(max,Integer.MIN_VALUE);
        for(int i = 0; i<matrix.length; i++){
            for(int j =0; j<matrix[i].length; j++){
                min[i] = Math.min(min[i],matrix[i][j]);
                max[j] = Math.max(max[j],matrix[i][j]);
            }
        }
        for(int i=0;i<matrix.length;i++){
            for(int j =0; j<matrix[i].length; j++){
                if(matrix[i][j] == min[i] && matrix[i][j]==max[j]){
                    list.add(matrix[i][j]);
                }
            }
        }
        return list;
    }
}
```