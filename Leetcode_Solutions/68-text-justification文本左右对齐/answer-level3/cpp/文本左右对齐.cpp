### 解题思路
此处撰写解题思路
1、每行出现的单词，按照字符数量限制的条件进行分割。
2、对于每一行的字符，按照要求，插入空格。
### 代码

```cpp
class Solution {
	string processForOneLine(vector<string> &linewords,int maxWidth, bool bIslast)
	{
		string res = linewords[0];
		int cnt = linewords.size();
		int totallen = 0;
		//只有一个特殊处理。后续都要补充空格
		if (cnt == 1)
		{
			int spacecnt = maxWidth - res.size();
			while (spacecnt-- > 0)
				res += ' ';
			return res;
		}
		//至少有2个
		for (int i = 0; i < cnt; i++)
		{
			totallen += linewords[i].size();
		}
		//最后一行。则每两个之间+1个空格，最后补齐即可。
		if (bIslast)
		{
			for (int i = 1; i < cnt; i++)
			{
				res += ' ' + linewords[i];
			}
			int space_cnt = maxWidth - res.size();
			while (space_cnt-- > 0)
				res += ' ';
            return res;
		}
		//对于非最后一行处理
		int qujian = cnt-1; //区间个数
		int space_cnt = maxWidth - totallen;
		int eachQJ_space = space_cnt / qujian;
		int eachQJ_Ys = space_cnt % qujian;
		for (int i = 1; i < cnt; i++,eachQJ_Ys--)
		{
			//中间补空格
			int space_size = eachQJ_space + (eachQJ_Ys > 0 ? 1 : 0);
			while (space_size-- > 0)
				res += ' ';
			//+后续的单词
			res += linewords[i];
		}
		if (res.size() != maxWidth)
			printf("error happen.\n");
		return res;
	}
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> res;
		int size = words.size();
		string line;
		int space = 0;
		vector<string> linewords;
		linewords.push_back(words[0]);
		int totalsize = words[0].size();
		
		for (int i = 1; i < size; i++)
		{
			//判断第i是否是最优解
			int cur = words[i].size();
			if (totalsize + cur < maxWidth)
			{
				totalsize = totalsize + cur + 1;
				linewords.push_back(words[i]);
			}
			else
			{
				res.push_back(processForOneLine(linewords, maxWidth, false));
				linewords.clear();
				linewords.push_back(words[i]);
				totalsize = words[i].size();
			}
		}
		//最后一个
		if (!linewords.empty())
		{
			res.push_back(processForOneLine(linewords, maxWidth,true));
		}
		return res;
	}
};

```