### 解题思路
双百C++,将int转string，再将string中单个字符（char）转string，再将string转const char*，最后转成int
![image.png](https://pic.leetcode-cn.com/38cfb67439d839e3b369e80b62bd624a1f9d3e5222d2b7fb49c4557fa8a93531-image.png)

### 代码

```cpp
class Solution {
public:
	int subtractProductAndSum(int n) {
		int plus = 0, multi = 1; int temp;
		string str = to_string(n);

		for (int i = 0; i < str.size(); i++)
		{
			string s(1, str[i]);
			const char* k1 = s.c_str();
			plus += stoi(k1);
			multi = multi*stoi(k1);

		}
		
		cout << multi << endl;
		//for(int i=)
	return (multi - plus);
	}
};
```