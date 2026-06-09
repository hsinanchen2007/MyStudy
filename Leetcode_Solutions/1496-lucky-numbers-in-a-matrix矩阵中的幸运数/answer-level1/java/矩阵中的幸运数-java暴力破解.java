### 解题思路
此处撰写解题思路
首先，用for循环找出第一行的最小值，同时记录该最小值的列，
之后用for循环找出该列的最大值，如果最小值和最大值相等，则该数是幸运数，
之后同理，依次遍历

### 代码

```java
class Solution {
    public List<Integer> luckyNumbers (int[][] matrix) {
        if(matrix==null){
            return null;
        }
        int m = matrix.length,n = matrix[0].length;
        Map<Integer,Integer> map = new HashMap<>();
        List<Integer> ans = new ArrayList<>();
        for(int i=0;i<m;i++){
            int max = Integer.MIN_VALUE,min = Integer.MAX_VALUE;
            for(int j=0;j<n;j++){
                map.put(matrix[i][j],j);
                min = Math.min(min,matrix[i][j]);
            }
            int min_col = map.get(min);
            map.clear();
            for(int k=0;k<m;k++){
                max = Math.max(matrix[k][min_col],max);
            }
            if(max==min){
                ans.add(max);
            }
        }
        return ans;
    }
}
```