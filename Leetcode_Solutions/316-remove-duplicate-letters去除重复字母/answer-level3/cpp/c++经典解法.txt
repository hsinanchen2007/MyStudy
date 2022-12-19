思路直接看注释简单明了，就是纯栈的灵活运用
code:
class Solution {
public:
   int flag(vector<char>V, string s, int i)  //接口：判断当前元素的后面是否存在相同元素与V.top()
	{
		int flag = 0;
		if (!V.empty())
			for (int j = i + 1;j < s.size();j++)
			{
				if (V.back() == s.at(j))
				{
					flag = 1;
					return flag;
				}
			}
		return flag;
	}

	string removeDuplicateLetters(string s)
	{
		vector<char>v;
		for (int i = 0; i < s.length(); i++)
		{
			char c = s.at(i);
			if (!v.empty())                   //栈里面是否存在当前元素，存在则直接过滤跳过
			{
				vector<char>::iterator It= find(v.begin(), v.end(), c);
				if (It!=v.end())
				{
					vector<char>::iterator it = find(v.begin(), v.end(), c);
					if (*it == c)
					{
						continue;
					}
				}
				
			}
						
			while (!v.empty()&&v.back()>c&&flag(v ,s,i)) //栈非空，且栈顶元素大于当前元素且当前元素后面还存在栈顶元素
			{
				v.pop_back();			
			}
			v.push_back(c);
		}
		//char *arr =new char[v.size()];
		string str;
		for (int i=0;i<v.size();i++)
		{			
			str += v.at(i);
		}
		return str;
	}
};