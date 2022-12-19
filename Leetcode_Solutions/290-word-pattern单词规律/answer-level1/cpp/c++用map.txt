```
#include <map>
#include <string>
#include <vector>
using namespace std;
//先将str拆解到vector中
//判断pattern的长度与vec的长度是否相等
//创建数组used用于记录pattern中的字母是否被使用过，这是重点
//建立string与char的map，遍历并比较
class Solution {
public:
	bool wordPattern(string pattern, string str) {
		if (str.length() < 1)
		{
			return false;
		}
		//将str拆解放入vector中
		vector<string> str_vec;
		string word = "";

		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == ' ')
			{
				str_vec.push_back(word);
				word = "";
				i++;
			}
			word += str[i];
			//str到最后一个字母时，将word插入
			if (i == str.length() - 1)
				str_vec.push_back(word);
		}

		//长度不一致，返回false
		if (pattern.length() != str_vec.size())
		{
			return false;
		}
		//从前向后遍历并插入map
		char used[128] = { 0 };//记录字母是否被使用；理解题中的双向对应，ASCII一共128个
		map<string, char> s_c_map;//string为key，char为value
		for (int i = 0; i < str_vec.size(); i++)
		{
			//找到了
			if (s_c_map.find(str_vec[i]) != s_c_map.end())
			{
				//没对应上
				if (s_c_map[str_vec[i]] != pattern[i])
				{
					return false;
				}
			}
			//没找到
			if (s_c_map.find(str_vec[i]) == s_c_map.end())
			{
				//字母被使用过
				if (used[pattern[i]] == 1)
				{
					return false;
				}
				//字母没有被使用过
				if (used[pattern[i]]==0)
				{
					//建立映射
					s_c_map[str_vec[i]] = pattern[i];
					//置1，表示字母被使用了，后面不能不允许建立字符串与这与字符的对应了，
					//以满足题中双向连接的对应规律
					used[pattern[i]] = 1;
				}
			}
		}
		return true;
	}
};
```
