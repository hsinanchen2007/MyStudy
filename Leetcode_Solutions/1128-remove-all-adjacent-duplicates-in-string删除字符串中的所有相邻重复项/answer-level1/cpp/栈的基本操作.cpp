### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string removeDuplicates(string S) 
{
	stack<char> st;
	int len=S.length();
	for(int i=0;i<len;i++)
	{
		if(!st.empty())
		{
			if(st.top()==S[i]) st.pop();
			else st.push(S[i]);
		}
		else st.push(S[i]);
	}
	string ss="";
	while(!st.empty())
	{
		ss=st.top()+ss;
		st.pop();
	}
	return ss;
}
};
```
以上就是对栈的基本操作.
没什么技巧可言.
这里总的来说是通过c++的stl来实现的,所以没有内存够不够一说的担忧,算法题练习是可以不用过于关系底层实现的.
重要的是能够想出解决问题的思路,并进而用相关的只是实现即可.
以上的解题的时间复杂度是O(n)
这应该是显而易见的.