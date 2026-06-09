## 思路:

回溯算法

记录 行, 列, 正对角,负对角,不能有两个以上的棋子.

如何判断是否在对角上呢?

正对角就是相加之和一样的

负对角就是相减只差一样的

------



## 代码:

```python [1]
class Solution:
    def totalNQueens(self, n: int) -> int:
        self.res = 0
        def backtrack(i,col,z_diagonal,f_diagonal):
            if i == n:return  True
            for j in range(n):
                if j not in col and i + j not in  z_diagonal and i - j not in f_diagonal:
                    if backtrack(i+1, col | {j}, z_diagonal |{i + j} , f_diagonal |{i - j}  ) :
                        self.res += 1
            return False
        backtrack(0,set(),set(),set())    
        return self.res
```



```java [1]
class Solution {
    int res = 0;
    public int totalNQueens(int n) {
        Set<Integer> col = new HashSet<>();
        Set<Integer> z_diagonal = new HashSet<>();
        Set<Integer> f_diagonal = new HashSet<>();
        
        backtrack(0, n,col, z_diagonal, f_diagonal);
        return res;   
    }
    private boolean backtrack(int i, int n,Set<Integer> col, Set<Integer> z_diagonal, Set<Integer> f_diagonal) {
        if (i == n) {
            return true;
        }
        for (int j = 0; j < n; j++) {
            if (!col.contains(j) && !z_diagonal.contains(i + j) && !f_diagonal.contains(i - j)) {
                col.add(j);
                z_diagonal.add(i + j);
                f_diagonal.add(i - j);
                if (backtrack(i+1,n,col,z_diagonal,f_diagonal)) res += 1;
                col.remove(j);
                z_diagonal.remove(i + j);
                f_diagonal.remove(i - j);
            }
        }
        return false;
    }
}
```

