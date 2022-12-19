问题分析:  
n代表有 n个'(' 和m个')' (n=m)  ，假设字符串str为"",每次添加括号可以分为以下几种情况:
当 n=m 并且 n>0时,只能添加 '('  因为此时')' 没有'(' 与之匹配 
当 n<m 并且 n>0时,可以添加 '(',也可以添加')' 等于有两条分支
当 m>n 异常情况
当 n==0时，'('已使用完毕，只需要将剩余的')'全部添加进去即可，代码如下:

/*
n:剩余( 个数
m: 剩余 ）个数
n=m 且n>0只能 (
n<m 且n>0  可以(   或 )
m<n 错误
n=0  添加m个 )	
*/
void generateP(vector<string>& result, string str, int n, int m) {
	if (n == m && n > 0) {
		str += "(";
		generateP(result, str, n - 1, m);
	}
	else if (n < m && n>0) {
		string temp = str;
		temp += "(";
		generateP(result, temp, n - 1, m);
		str += ")";
		generateP(result, str, n, m - 1);
	}
	else if (n == 0) {
		while (m > 0)
		{
			str += ")";
			m--;
		}
		result.push_back(str);
	}
}

vector<string> generateParenthesis(int n) {
	vector<string> result;
	generateP(result,"", n,n);
	return result;
}
