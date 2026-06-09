### 解题思路
此处撰写解题思路
就是简单的整除求余方式，只不过这道题目不是逢26进1，而是Z代表26，需要注意余数为0的时候条件判断一下。
### 代码

```cpp
class Solution {
public:
    string convertToTitle(int n) {
    string str="";
	vector<char> vec;
	while(n>0)
	{
		int tn = n/26;
		int ty = n - 26*tn;
		n = tn;
		if(ty==0)
		{
			ty = ty+26;
			n = n-1;
		}
		vec.push_back(ty+64);
	}
	for(int i=vec.size()-1;i>-1;--i)
	{
		str = str+vec[i];
	}
    return str;
    }
};
```