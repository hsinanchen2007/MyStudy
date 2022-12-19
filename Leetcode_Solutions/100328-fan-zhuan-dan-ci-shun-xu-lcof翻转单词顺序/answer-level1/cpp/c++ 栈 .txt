### 解题思路
分享一个简单的思路，耗时可能多点
执行用时 :
4 ms
, 在所有 C++ 提交中击败了
99.04%
的用户
内存消耗 :
10.9 MB
, 在所有 C++ 提交中击败了
100.00%
的用户
  ### 1.一次遍历将所有的单词存储到栈中
  ### 2.依次拼接+空格
  ### 3.删除最后的一个空格 string中erase（）函数可搞定

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {

stack<string> words;
	string word="";
	string res = "";
	for (int i = 0; i < s.size(); i++)
	{
		word = "";
		while (i<s.size()&&s[i] != ' ')
		{
			word += s[i];
			i++;
		}
		if (word.size() > 0)
		{
			words.push(word);
		}
	}
	while(!words.empty())
	{
		res += words.top();
		res += " ";
		words.pop();
	}
	//删除最后一个空格
	res.erase(res.end() - 1);
	return res;
    }
};
```