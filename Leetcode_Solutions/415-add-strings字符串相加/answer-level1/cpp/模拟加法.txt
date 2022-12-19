执行用时 :16 ms, 在所有 C++ 提交中击败了45.09%的用户
内存消耗 :7 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
	string addStrings(string num1, string num2) 
	{
		string res;
		int i = num1.size() - 1, j = num2.size() - 1;
		int carry = 0;
		while (i >= 0 || j >= 0)
		{
			int n1 = i >= 0 ? num1[i]-'0' : 0;
			int n2 = j >= 0 ? num2[j]-'0' : 0;
			int tem = n1 + n2 + carry;
			carry = tem / 10;
			res += to_string(tem % 10);
			i--; j--;
        }
		if (carry == 1) res += '1';
		reverse(res.begin(), res.end());
		return res;
	}
};
```