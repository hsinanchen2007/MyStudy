### 解题思路
自带剪枝
不用剩余括号数
而是剩余可用括号数

### 代码

```java
class Solution {
	List<String> res = new ArrayList<String>();
    public List<String> generateParenthesis(int n) {
    	helper(n, 0,"");
    	return res;
    }
    
    void helper(int l,int r,String s) {
    	if(l==0 && r==0) {
    		res.add(s);
    		return;
    	}
    	if(l>0)helper(l-1, r+1,s+"(");
    	if(r>0)helper(l, r-1,s+")");
    	
    	
    }
}
```