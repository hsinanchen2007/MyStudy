首先这是问题I+II的叠加，考虑用递归加栈
遇到( 符号的时候，进行递归，找到与其对应的右括号，这里找寻右括号的方式是一个小技巧，
把左括号计数为1，为了防止内部还有括号，向右遍历，遇到左括号+1，右括号-1直到搜索结束完毕，如果还有子区间有括号那么继续递归下去，直到最小的括号区间。
为了减少用栈的数量，通过设定符号sign初始值为‘+’；
如果在向后遍历的过程中，遇到了符号或者搜索了尾部，
如果遇到了正号，那么直接将num推入栈，
如果为-号，直接推入-num
如果为*/就需要和栈顶的元素进行计算，再推入结果；
注意！ 因为初始sign为+所以，第一个数被看做是正数推入，然后再将
sign赋值成当前符号。

//stack保存着一系列的值，通过相加得到某个递归部分的num
最后推出res,但是int类型好像不太够，有个越界的测试用例，改成long就过了。。






```
class Solution {
public:
	int calculate(string s) {
		char sign = '+';
		long num = 0;
		long res = 0;
		stack<long>x;
		int i = 0;
		while (i < s.size()) {
			if (s[i] >= '0'&&s[i] <= '9') {
				num *= 10;
				num += s[i] - '0';
			}
			else if (s[i] == '(') {
				int cnt = 0;
				int j = i;
				for (; i < s.size(); i++) {
					if (s[i] == '(')cnt++;
					if (s[i] == ')')cnt--;
					if (cnt == 0)break;
				}
				num = calculate(s.substr(j + 1, i-j - 1));
			}
			if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || i == s.size() - 1) {
				if (sign == '+')x.push(num);
				else if (sign == '-')x.push(-num);
				else if (sign == '*') {
					int temp = x.top(); x.pop();
					x.push(temp*num);
				}
				else if (sign == '/') {
					int temp2 = x.top(); x.pop();
					x.push(temp2 / num);
				}
				sign = s[i];
				num = 0;
			}
			i++;
		}
		//记录了所有的值，最后在栈中进行相加
		while (!x.empty()) {
			res += x.top(); x.pop();
		}
		return res;
	}
};
```

