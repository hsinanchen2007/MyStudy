有效括号字符串 仅由 "(" 和 ")" 构成，并符合下述几个条件之一：
空字符串
连接，可以记作 AB（A 与 B 连接），其中 A 和 B 都是有效括号字符串
嵌套，可以记作 (A)，其中 A 是有效括号字符串

忽略空字符串，只剩连接和嵌套。
连接的嵌套深度是不累加的，所以想要嵌套深度最小，只要把seq中嵌套的括号拆开分给AB即可。

观察两种情况
    连接："()()()"   嵌套："(())" 
可以发现，连接和嵌套的区别是  "(" 的前面是"("还是")"

定义一个bool类型的flag，记录上一个字符是属于A还是B。

当seq[i]='('时，将i入栈。判断seq[i-1]是否为"("，若是则flag取反，反之不变。答案数组answer[i]赋值为flag。
当seq[i]=')'时，answer[i]赋值为栈顶元素的answer值，并将栈顶元素出栈。

```
class Solution {
public:
	vector<int> maxDepthAfterSplit(string seq) {

		vector <int>answer; answer.clear();
		stack<int> d; 

		int i;
		bool flag = 0; 

		for (i = 0; i < seq.size(); i++)
		{
			if (seq[i] == '(')
			{
				if(i>0&&seq[i-1]=='(')
				flag = !flag;

				d.push(i);
				answer.push_back(flag);
			}

			else
			{
				answer.push_back(answer[d.top()]);
				d.pop();
			}
			flag = answer[i];
		}

		return answer;
	}
};
```


