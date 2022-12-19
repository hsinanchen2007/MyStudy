学习了上传的其他解题方法，写了java版本的。
没有太多技巧，比价暴力。具体过程可以看另一篇解法。
```java
class Solution {
    public int countCornerRectangles(int[][] grid) {
        int n = grid.length;
        if(n == 0)
            return 0;
        int m = grid[0].length;
        if(m == 0)
            return 0;
        int res = 0;
        for(int i = 0; i < n; i ++){
            ArrayList<Integer> have = new ArrayList<>();
            for(int k = 0; k < m; k ++){
                if(grid[i][k] == 1)
                    have.add(k);
            }
            for(int j = i+1; j < n; j ++){
                int count = 0;
                for(int k = 0; k < have.size(); k ++){
                    if(grid[j][have.get(k)] == 1)
                        count ++;
                }
                res += count*(count-1)/2;
            }
        }
        return res;
    }
}
```