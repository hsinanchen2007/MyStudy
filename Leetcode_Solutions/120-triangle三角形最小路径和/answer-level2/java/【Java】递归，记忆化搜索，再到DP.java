
# 递归，自顶向下 【超时】
```java
int row;

public int minimumTotal(List<List<Integer>> triangle) {
    row=triangle.size();
    return helper(0,0, triangle);
}
private int helper(int level, int c, List<List<Integer>> triangle){
    // System.out.println("helper: level="+ level+ " c=" + c);
    if (level==row-1){
        return triangle.get(level).get(c);
    }
    int left = helper(level+1, c, triangle);
    int right = helper(level+1, c+1, triangle);
    return Math.min(left, right) + triangle.get(level).get(c);
}
```

**改进,避免重复计算**

# 自顶向下, 记忆化搜索 【AC】
```java
int row;
Integer[][] memo;

public int minimumTotal(List<List<Integer>> triangle) {
    row = triangle.size();
    memo = new Integer[row][row];
    return helper(0,0, triangle);
}
private int helper(int level, int c, List<List<Integer>> triangle){
    // System.out.println("helper: level="+ level+ " c=" + c);
    if (memo[level][c]!=null)
        return memo[level][c];
    if (level==row-1){
        return memo[level][c] = triangle.get(level).get(c);
    }
    int left = helper(level+1, c, triangle);
    int right = helper(level+1, c+1, triangle);
    return memo[level][c] = Math.min(left, right) + triangle.get(level).get(c);
}
```

# 自底向上, DP 【AC】
```java
public int minimumTotal(List<List<Integer>> triangle) {
    int row = triangle.size();
    int[] minlen = new int[row+1];
    for (int level = row-1;level>=0;level--){
        for (int i = 0;i<=level;i++){   //第i行有i+1个数字
            minlen[i] = Math.min(minlen[i], minlen[i+1]) + triangle.get(level).get(i);
        }
    }
    return minlen[0];
}
```

