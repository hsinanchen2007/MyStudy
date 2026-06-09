### 解题思路
list存行最小数，再找行最大数，如果list存在，则存入ans数组。

### 代码

```java
class Solution {
    public List<Integer> luckyNumbers (int[][] matrix) {
        List<Integer> list = new ArrayList<>();
        List<Integer> ans = new ArrayList<>();
        for(int i = 0;i<matrix.length;i++){
            int min = Integer.MAX_VALUE;
            for(int j = 0;j<matrix[0].length;j++){
                min = Math.min(matrix[i][j],min);
            }
            list.add(min);
        }
        for(int i = 0;i<matrix[0].length;i++){
            int max = Integer.MIN_VALUE;
            for(int j = 0;j<matrix.length;j++){
                max = Math.max(matrix[j][i],max);
            }
            if(list.contains(max)){
                ans.add(max);
            }
        }
        return ans;
    }
}
```