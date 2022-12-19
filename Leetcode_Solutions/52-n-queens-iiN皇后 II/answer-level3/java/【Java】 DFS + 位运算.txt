
深度优先搜索相对比较简单，加上剪枝很容易完成
```
class Solution {
    
    Set<Integer> colsSet = new HashSet();
    Set<Integer> pieSet = new HashSet();
    Set<Integer> naSet = new HashSet();
    
    int res = 0;
    
    public int totalNQueens(int n) {
        
        if (n < 1) {
            return res;
        }
        
        backtrack(0, n);
        
        return res;
        
    }
    
    public void backtrack(int row, int n) {
        
        if (row == n) {
            
            res++;
            return;
        }
        
        for (int i = 0; i < n; i++) {
            if (colsSet.contains(i) || pieSet.contains(row + i) || naSet.contains(row - i)) {
                continue;
            }
            
            colsSet.add(i);
            pieSet.add(row + i);
            naSet.add(row - i);
            
            backtrack(row + 1, n);
            
            colsSet.remove(i);
            pieSet.remove(row + i);
            naSet.remove(row - i);
            
        }
        
    }
}
```

位运算相对来说比较不好理解，当然位运算也离不开dfs，只不过剪枝效果更加明显，终极解法
```
class Solution {
  
    
    int res = 0;
    
    public int totalNQueens(int n) {
        
        if (n < 1) {
            return res;
        }
        
        backtrack(0, 0, 0, 0, n);
        
        return res;
        
    }
    
    /**
    * col, pie, na分别表示 纵列，撇，捺 皇后放的位置
    * col|pie|na 或操作，比如如果col = 0010， pie = 0101，na = 1011，col|pie|na 算出来所有放过皇后的地方
    * ~(col|pie|na) 倒装一下，没放过皇后的地方设置为1， 再 &((1<<n)-1) 表示只取低位，不需要高位
    * 所以bits表示所有未放皇后的地方
    **/
    
    public void backtrack(int row, int col, int pie, int na, int n) {
        
        if (row >= n) {
            res++;
            return;
        }
        
        // 所有未放皇后的位置
        int bits = (~(col|pie|na)) & ((1<<n) -1);
        
        while (bits > 0) {
            
            // 找到bits的最后一个1
            int p = bits & (-bits);
            
            // col|p 表示col中加一个1， (pie|p)<<1 表示要往左下角移动，(na|p)往右下角移动
            backtrack(row + 1, col|p, (pie|p) << 1, (na|p) >> 1, n);
            
            // bit&(bits-1) 是去掉最后一个1的操作
            bits &= bits-1;
        }
            
      
    }
}
```

