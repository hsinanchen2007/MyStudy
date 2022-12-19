C++ 好像没有类似replaceAll的函数，只能每次找到空格，然后替换该位置的数据了。
但这个写法，在这道题里可行，不代表所有题都可行，这不是个通用的方法。应为如果一次替换后，产生了新的要替换的字符串该方法就不对了。比如将"12212"中"12"替换成"21"，正确答案为"21221"，而该方法输出结果为"22211"。
```C++ []
class Solution {
public:
	string replaceSpace(string s) {
		while(s.find(" ") != string::npos) {
			s.replace(s.find(" "), 1, "%20");
		}
		return s;
	}
};
```
