### 解题思路
先用map建立起数字和字符的映射关系，再通过回溯实现全排列

### 代码

```cpp
class Solution 
{
public:
	vector<string> letterCombinations(string digits) 
	{
        if (digits == "")
		{
			return {};
		}
		map<char, string> mymap =
		{
		  { '2',"abc" },{ '3',"def" },
		  { '4',"ghi" },{ '5',"jkl" },{ '6',"mno" },
		  { '7',"pqrs" },{ '8',"tuv" },{ '9',"wxyz"} 
		};
		vector<string> res;
		string temp;

		backtrack(res, temp, mymap, digits, 0);
		return res;
	}

	void backtrack(vector<string> &res, string temp, map<char, string> mymap, string digits, int begin)
	{
		if (temp.size() == digits.size())
		{
			res.push_back(temp);
		}
		else
		{
			for (int i = 0; i < mymap[digits[begin]].size(); ++i)
			{
				temp.push_back(mymap[digits[begin]][i]);
				backtrack(res, temp, mymap, digits, begin + 1);
				temp.pop_back();
			}
		}
	}
};

```