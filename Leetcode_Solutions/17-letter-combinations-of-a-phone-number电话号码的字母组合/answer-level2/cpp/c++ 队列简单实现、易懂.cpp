方法概述：
利用数据结构中队列的“先进先出”的知识，采用实时更新队列的内容实现遍历。
步骤说明：
1.建立一个map哈希表；
2.新建一个队列；
3.将第一个字符串所对应的码表逐步进入到队列中；
4.出队操作，存储当前出队的string；
5.将此string与后一个字符串所对应的码表中每一个值相加并逐步进入到队列中；
6.最终队列中存储的即为所有情况的string
代码描述：
```
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> res;//用于输出向量
		map<char, string> m = { {'2',"abc" },{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"} };//映射map哈希表
		int size = digits.size();//输入字符串产长度
		queue<string> que;//新建队列
		
		//先将第一个元素对应的码表入队
		for (int j = 0; j < m[digits[0]].size(); j++)
		{
			string str;
			str.push_back(m[digits[0]][j]);//char转string
			que.push(str);//string入队
		}
		string s;//用于存储队头元素
		for (int i = 1; i < size; i++)
		{
			int length = que.size();//当前队列长度
			while (length--)
			{
				for (int j = 0; j < m[digits[i]].size(); j++)
				{
					s = que.front();
					s = s + m[digits[i]][j];//队头元素加上新元素
					que.push(s);//入队
				}
				que.pop();//队头出队
			}
		}
		while (!que.empty())
		{
			res.push_back(que.front());//队头元素存储至res
			que.pop();//队头出队
		}
		return res;//返回
	}
};
```

