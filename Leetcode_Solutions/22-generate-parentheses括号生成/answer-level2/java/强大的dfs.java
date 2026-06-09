### 解题思路
注意一点：验证程序中用到的static要去掉，否则不通过，可能是leetcode的验证程序设定的原因

### 代码

```java
class Solution {
	List<String>res = new ArrayList<String>();
    public List<String> generateParenthesis(int n) {
    	search(n, n, "");
    	return res;
    }
    private  void search(int left,int right,String curString) {
		if (left==0&&right==0) {  //递归终止的base case，左右都不剩即终止
			res.add(curString);
			return;
		}
		if (left>0) {  //如果左括号还剩余，可以拼接左括号
			search(left-1, right, curString+"(");
		}
		if (right>left) { //如果右括号剩余多于左括号剩余，可以拼接右括号
			search(left, right-1, curString+")");
		}
	}
}
```