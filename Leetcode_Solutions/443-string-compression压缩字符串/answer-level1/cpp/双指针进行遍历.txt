### 解题思路
此处撰写解题思路
题目的输入有些问题，明明是字符数组，却写成字符串数组
### 代码

```cpp
class Solution {
    bool IsValidChar(char c)
    {
	    if (c >= 35 && c <= 126)
		    return true;
	    return false;
    }

void ChangeVec(vector<char>&vec, int val)
    {
	    vector<int>vecres;
	    do 
	    {
		    vecres.push_back(val % 10);
		    val = val / 10;
	    } while (val != 0);
	    reverse(vecres.begin(), vecres.end());
	    for (auto &val : vecres)
		    vec.push_back('0' + val);

    }
public:
    int compress(vector<char>& chars) {
        vector<char> vecres;
	    if (chars.size() == 0 || chars.size() > 1000)
		    return -1;
	    for (auto& val : chars)
	    {
		    if (!IsValidChar(val))
		    	return -1;
	    }
	    auto iterpre = chars.begin();
	    auto iterend = chars.begin();

	    while (iterpre != chars.end())
	    {
		    while (iterend!=chars.end()&&*iterpre == *iterend)
			    iterend++;
		    if (iterend - iterpre > 1)
		    {
			    vecres.push_back(*iterpre);
			    ChangeVec(vecres, (iterend - iterpre));
		    }
		    else
		    {
			    vecres.push_back(*iterpre);
		    }
		    iterpre = iterend;
	    }
	    chars = vecres;
	    return chars.size();
        }
};
```