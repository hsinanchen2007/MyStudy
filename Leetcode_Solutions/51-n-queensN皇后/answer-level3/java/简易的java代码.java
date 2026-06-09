### 代码

```java
public class Solution {
	public List<List<String>> solveNQueens(int n){
		List<List<Integer>> solutions = getSolutions(n);
		List<List<String>> res = traverse(solutions,n);
		return res;
	}
	
	public List<List<Integer>> getSolutions(int n){
		List<List<Integer>> solutions = new ArrayList<>(); 
		List<Integer> row = new ArrayList<>();
		backtrack(solutions,row,n);
		return solutions;
	}
	
	public void backtrack(List<List<Integer>> solutions,List<Integer> row,int n){
		if(row.size() == n){
			solutions.add(new ArrayList<>(row));
		}
		for(int col=0;col<n;col++){
			if(!check(row,n,col)){
				continue;
			}
			row.add(col);
			backtrack(solutions,row,n);
			// 回退（移除最后一步决策）
			row.remove(row.size()-1);
		}
	}
	
	public boolean check(List<Integer> row,int n,int col){
		// 用数组row来保存放置位置，本身已经避免了摆在同一行的情况
		// check方法只需要检查是否存在摆放在同一列、同一对角线这两种情况
		// 若可以摆放返回true，不能摆放返回false
		int currRow = row.size();
		for(int i=0;i<row.size();i++){
			if(row.get(i) == col){
				// 存在同一列的元素
				return false;
			}
			for(int j=0;j<row.size();j++){
				if(col-row.get(j) == currRow-j || col-row.get(j) == j-currRow){
					// 存在处于同一对角线的元素（列之差与行之差的斜率之比为1或-1）
					return false;
				}
			}
		}
		return true;
	}
	
	public List<List<String>> traverse(List<List<Integer>> solutions,int n){
		List<List<String>> res = new ArrayList<>();
		for(int i=0;i<solutions.size();i++){
			List<String> oneSolution = new ArrayList<>();
			List<Integer> curr = solutions.get(i);
			for(int j=0;j<n;j++){
				int col = curr.get(j);
				StringBuilder sb = new StringBuilder();
				for(int k=0;k<n;k++){
					if(k==col){
						sb.append('Q');
					}else{
						sb.append('.');
					}
				}
				String row = sb.toString();
				oneSolution.add(row);
			}
			res.add(oneSolution);
		}
		return res;
	}
}

```

### 欢迎与我交流

![wechat.png](https://pic.leetcode-cn.com/9fcfd3a5c8e56ac147ca0c8ad4e0588a3f20d970f3a77031c81bc59f9eb43c63-wechat.png)
