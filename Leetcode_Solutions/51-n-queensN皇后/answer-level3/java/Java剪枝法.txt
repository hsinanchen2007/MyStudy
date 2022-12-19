基本思路是深度优先，剪枝，回溯过程记得还原
感谢评论区 
[@powcai](/u/powcai)这位兄台的
```
    char[] s = new char[n];
    Arrays.fill(s, '.');
    s[i] = 'Q';
```
这段逻辑，非常巧妙！




```
class Solution {
    
    Set<Integer> colSet = new HashSet();
    
    Set<Integer> pieSet = new HashSet();
    
    Set<Integer> naSet = new HashSet();
    
    public List<List<String>> solveNQueens(int n) {
        
        List<List<String>> res = new ArrayList();
        
        
        if (n < 1) {
            return res;
        }
        
        
        backtrack(res, n, 0, new ArrayList());
        
      
        return res;
        
    }
    
    public void backtrack(List<List<String>> res, int n, int row, List<String> temp) {
        if (row >= n) {
            
            res.add(new ArrayList(temp));
            return;
        }
        
        for (int i = 0; i < n; i++) {
            if (colSet.contains(i) || pieSet.contains(row + i) || naSet.contains(row - i)) {
                continue;
            }
            
            colSet.add(i);
            pieSet.add(row + i);
            naSet.add(row - i);
            
            char[] s = new char[n];
            Arrays.fill(s, '.');
            s[i] = 'Q';
            temp.add(new String(s));
            
            backtrack(res, n, row + 1, temp);

            temp.remove(temp.size() - 1);
            colSet.remove(i);
            pieSet.remove(row + i);
            naSet.remove(row - i);
            
        }
    }
}
```
