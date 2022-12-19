### 解题思路
我们假设已经确定了n个字符,以及其中'('的数量nl,')'的数量nr,
对于第n+1个字符，只能是'('或')',
	当nl<给定N时，可以递归计算第n+1个字符为'('的情况
	当nr<给定N 并且 nl>nr 时(注意括号的合法条件，当前左括号数量必须大于右括号数量)，可以递归计算第n+1个字符为')'的情况
	当nl+nr==2*给定N时递归结束，记录当前字符串

### 代码

```cpp
class Solution {
 public:
	 vector<string> res;
	 int N;
	 //Para:	当前字符串，左括号数量，右括号数量
	 void getParenthesis(string rest, int nl, int nr)
	 {
		 //结束条件
		 if (rest.size() == 2 * N)
		 {
			 res.push_back(rest);
			 return;
		 }

		 //假设前几个括号已经确定下来，我们需要考虑下一个是 ( 还是 )
		 //考虑插入 (
		 if (nl < N)
		 {
			 string lrest = rest;
			 lrest.push_back('(');
			 getParenthesis(lrest, nl + 1, nr);
		 }
		 //考虑插入 )	,注意括号的合法性：即当前字符中 ( 的数量必须要大于等于 ) 的数量
		 if (nr < N && nr < nl)
		 {
			 rest.push_back(')');
			 getParenthesis(rest, nl, nr + 1);
		 }
	 }
	 vector<string> generateParenthesis(int n) {
		 if (n == 0)
			 return vector<string>{""};
		 this->N = n;
		 string begs("(");
		 getParenthesis(begs, 1, 0);
		 return res;
	 }
 };
```