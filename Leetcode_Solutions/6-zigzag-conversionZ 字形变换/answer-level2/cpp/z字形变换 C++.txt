### 解题思路

	通过简单的数学归纳，发现可以通过numRows进行分段，每段的元素个数为2*numRows-2
    例如当numRowsnumRows=4时，每段有六个元素
	L E E T C O/ D E I S H I /R I N G
    输出每段第一个元素即 L D R

    去掉每段第一个元素后变成
    E E T C O/  E I S H I / I N G

    然后输出每段的第一个和最后一个,但是要保证在s范围内
    （段不满的时候，eg第三段的ING 最后一个不是G）：EO EI I
    这时第一趟结束后 ++left --right

    相当于去掉之前输出的元素后变成：E T C / I S H / N G
    然后输出每段的第二个和倒数第二个EC IH N

    此意类推最后输出： T S G

    最后结果为  L D R / EO EI I/ EC IH N / T S G


### 代码

```cpp
class Solution {
public:
	string convert(string s, int numRows)
	{
		if (numRows == 1) return s;
		int duanSize = 2 * numRows - 2;
		int left = 1, right = duanSize - 1;
		int duanNum = (s.size() + duanSize - 1) / duanSize; //向上取整的写法
		string res;
		for (int i = 0; i < duanNum; ++i)
		{
			res.push_back(s[i * duanSize]);
		} //将每段的第一个元素先输出
		while (left < right)//如果写left<=right 最后一趟容易重复输出
		{
			for (int i = 0; i < duanNum; ++i)
			{
				if(left + i * duanSize < s.size())
				res.push_back(s[left   + i*duanSize]);
				if (right + i * duanSize < s.size())
				res.push_back(s[right + i*duanSize]);
			}
			left++;
			right--;
		}
		if (left == right) 
		{
			for (int i = 0; i < duanNum; ++i)
			{
				if (left + i * duanSize < s.size())
					res.push_back(s[left + i * duanSize]);
			}
		}
		return res;

	}
};
```