C++递归处理
```
class Solution {
public:
	string decodeString(const string& s) {
		string result;
		int count, bracket, hasChild;		//count：解码个数；bracket：括号计数器；hasChild：是否具有嵌套
		for (int i = 0; i < s.size(); i++) {
			string str;
			count = hasChild = bracket = 1;	//设置默认值
			if (isdigit(s[i])) {	//压缩的字符串
				count = 0;
				while (s[i] != '[') count = count * 10 + s[i++] - '0';
				++i;		//移至左括号的下一位
				do {		//此循环用于查找相匹配的右括号
					if (s[i] == '[' && !(hasChild = 0))	++bracket;	//如出现[说明有嵌套
					else if (s[i] == ']' && !--bracket)	break;
					str.push_back(s[i++]);
				} while (bracket != 0);
				if (hasChild == 0)			//递归处理嵌套
					str = decodeString(str);
			}
			else {			//裸字符串
				str += s[i];
				while (i + 1 < s.size() && !isdigit(s[i + 1])) str += s[++i];	
			}
			for (int j = 0; j < count; ++j)
				result += str;	
		}
		return result;
	}
};
```
