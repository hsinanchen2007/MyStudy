### 解题思路
优乐美

### 代码

```java
class Solution {
     /*
     * N皇后问题
     */
    HashSet<Integer> cols=new HashSet<>();
	HashSet<Integer> pies=new HashSet<>();
	HashSet<Integer> nas=new HashSet<>();
    //N皇后问题
    public List<List<String>> solveNQueens(int n) {
    	List<List<String>> res=new ArrayList<>();
    	List<List<Integer>> ans=new ArrayList<>();
    	if(n<1)return res;
    	_dfs(n,0,new ArrayList<Integer>(),ans);
    	return generateResult(res,ans);
    }

private List<List<String>> generateResult(List<List<String>> res,
			List<List<Integer>> ans) {
		if(ans.size()<1)return res;
		int n=ans.get(0).size();
		for(List<Integer> cur:ans) {
			List<String> lev=new ArrayList<>(n);
			//依次取出这n个数
			for(int row=0;row<n;row++) {
				char[] _row=new char[n];
				Arrays.fill(_row,'.');
				_row[cur.get(row)]='Q';
				lev.add(new String(_row));
			}	
			res.add(lev);
		}
		return res;
	}

	private void _dfs(int n, int row, List<Integer> ans,List<List<Integer>> res) {
		if(row>=n) {
			res.add(new ArrayList<>(ans));
			return;
		}
		for (int col = 0; col < n; col++) {
			if (cols.contains(col) || pies.contains(row + col) || nas.contains(row - col))
				continue;
			cols.add(col);
			pies.add(row+col);
			nas.add(row-col);
			ans.add(col);
			_dfs(n, row+1,ans,res);
			
			cols.remove(col);
			pies.remove(row+col);
			nas.remove(row-col);
			ans.remove(ans.size()-1);
		}
	}
}
```