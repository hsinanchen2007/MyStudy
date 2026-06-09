### 解题思路
用一个记录数组record记录当前的输出位置，例如digits="23"，record与digits大小相同
record更新步骤应为
[0,0]>[0,1]>[0,2]>[1,0]>[1,1]>[1,2]>[2,0]>[2,1]>[2,2]
record[0]=0指digits[0]即数字2的首字母即a,record[0]=1指b，record[1]=2指数字3中的f
更新次数即为输出字符串的个数应为digits所代表的字母数的乘积

### 代码

```cpp
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		//先确定数字-字符映射关系
		vector<string> i2smap{ {"abc"},{"def"},{"ghi"},{"jkl"},{"mno"},{"pqrs"},{"tuv"},{"wxyz"} };
		
		//共返回pow(3,digits.size())个字符串	23
		vector<string> res;

		if (digits.size() == 0)
			return res;
		//用来记录出现次数
		vector<int> record;
		for (int i = 0; i < digits.size(); i++)
			record.push_back(0);

		while (record[0]<i2smap[(int)(digits[0]-'2')].size())//结束条件，record中最左侧字符超过digits其所在i2smap中最大值
		{
			//输出当前情况的组合
			string str;
			for (int i = 0; i < record.size(); i++)
				str.push_back(i2smap[(int)(digits[i] - '2')][record[i]]);
			res.push_back(str);
			//digits最右侧字符record增加，只有当增加为当前满的时候，左侧增加
			record[record.size()-1]++;


			//更新record
			for (int i = digits.size()-2; i >=0; i--)
				if (record[i + 1] == i2smap[(int)(digits[i + 1] - '2')].size())
				{
					record[i]++;
					record[i + 1] = 0;
				}



		}



		return res;

	}
};

```