### 解题思路
参考 [Krahets的做法](https://leetcode-cn.com/problems/decode-string/solution/decode-string-fu-zhu-zhan-fa-di-gui-fa-by-jyd/) 这里用C++实现。
给一个C++的参考代码，思路上面链接比较清楚了。
举个例子：
`multi`和`res`分别表示准备入栈重复次数和当前的字符串
遇到`[`入栈，遇到`]`出栈
比如 `"2[ab2[c]]"`
- 遇到`[`, `<2, "">`入栈，此时还没有遇到字符串，所以有`res=""`，之后重新统计，`multi=0,res=""`
- 遇到`[`, `<2, "ab">`入栈，依次遇到`a`,`b`，所以有`res=ab`，之后重新统计，`multi=0,res=""`
- 遇到`]`, `<2, "ab">`出栈，`res="c"`，则更新`res="ab" + 2"c" = "abcc"`
- 遇到最外面的`]`，`<2, "">`出栈，`res="" + 2"abcc" = "abccabcc"`
得到最终结果，所以入栈的是下一个字符串的重复次数和当前字符串，也许正是因为这个不同时，让题目一下子不好解。
### 代码

```cpp

typedef pair<int, string> P;

class Solution {
public:
    string decodeString(string s) {
    	stack<P> st;
    	string res="";
    	int mutil(0);
	for(int i=0; i<s.size(); ++i) {
		if(s[i] >= '0' && s[i] <= '9') 
			mutil = 10*mutil + (s[i] - '0');
		else if(s[i] == '[') {
			st.push(make_pair(mutil, res));
			mutil = 0;
			res = "";
		}
		else if(s[i] == ']') {
			P cur = st.top();
			st.pop();
			res = cur.second + decode(cur.first, res); 
		}
		else 
			res += s[i];	
	}
		return res;
    }
    
    string decode(int n, string s) {
    	string r = "";
    	for(int i=0; i<n; ++i) {
    		r += s;
		}
		return r;
	}
};

```