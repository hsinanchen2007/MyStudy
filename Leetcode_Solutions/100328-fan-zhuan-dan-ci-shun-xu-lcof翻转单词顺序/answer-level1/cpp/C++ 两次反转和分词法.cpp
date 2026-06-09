### 解题思路
方法1：两次反转，空间复杂度o(1)
先翻转整个字符串，再对字符串里的每个单词进行翻转
对于整个字符串s中出的空格的处理：
- 如果是首尾空格，则使用s.erase()和s.find_first_not_of()和s.find_last_not_of()进行删除
- 对于中间的多余空格，进行遍历，对于多余的空格使用s.erase进行删除
对于特判情况的处理：
- 由于可能出现字符串全为空格的情况，因此应该先删除首尾空格，再判断字符串中字符个数是否为0

方法2：参考
[@adonis](/u/adonis/)的分词法，用空间换时间，也比较好理解，把每一个单词分出，然后逆序输出，看代码更清晰
### 代码

```cpp
class Solution {
public:
	string reverseWords(string s) {
	
		//删除首尾空格
		s.erase(0, s.find_first_not_of(" "));//find_first_not_of返回第一个与给出字符不相等的地址
		s.erase(s.find_last_not_of(" ") + 1);//find_last_not_of返回最后一个与给出字符不相等的地址
        //删除空格后，如果为空，则直接退出
        if (s.size()==0)
		{
			return "";
		}
		//删除中间多余空格
		int i = 0, j = 1;
		while (i<s.size()-1)
		{
			if (s[i]==' '&&s[j]==' ')
			{
				while (s[j]==' ')//统计从i处其有多少个空格
				{
					j++;
				}
				s.erase(i, j - 1 - i);//从i处开始，删除j-1个空格
				j = i + 1;//删除完后再返回到i的后面;
			}
			else//依次排查
			{
				i++;
				j++;
			}
		}
		//先翻转整个字符串
		Reversve(s,0, s.size()-1);
		//再翻转字符串里面的每一个串
		int pBegin=0,pEnd =0;
		while (s[pBegin]!='\0')//反转结束条件
		{
			if (s[pBegin]==' ')
			{
				pBegin++;
				pEnd++;
			}
			else if (s[pEnd]==' '||s[pEnd]=='\0')
			{
				Reversve(s,pBegin, --pEnd);
				pBegin = ++pEnd;
			}
			else
			{
				pEnd++;
			}
		}
		return s;
	}
	//反转函数
	void Reversve(string &s,int pBegin, int pEnd)
	{
		while (pBegin<pEnd)
		{
			char temp = s[pBegin];
			s[pBegin] = s[pEnd];
			s[pEnd] = temp;
			pBegin++, pEnd--;
		}
	}
};
```
方法2：分词法
```cpp
class Solution {
public:
	string reverseWords(string s) {
		vector<string> res;
		string word = "";//记录s中的每一个字符
		s += " ";//加上该空格，便于最后一个单词更好分离
		int i = 0;
		//分词
		while (i<s.size())
		{
			if (s[i]!=' ')//如果字符不为空格，则加入到word中
			{
				word += s[i];
			}else if (word.size()!=0)//如果为空格，且该word含有单词，则加入到res中
			{
				res.push_back(word);
				word = "";
			}
			i++;
		}
		//逆序输出
		string ans;
		for (int i=res.size()-1;i>=0;i--)
		{
			ans += res[i];
			if (i!=0)//除第一个单词外，每添加一个单词，则再添加一个空格
			{
				ans += " ";
			}
		}
		return ans;
	}
};
```

### 参考资料
[关于find_last_not_of和find_first_not_of的用法解释](https://blog.csdn.net/ffjbq/article/details/7611255)