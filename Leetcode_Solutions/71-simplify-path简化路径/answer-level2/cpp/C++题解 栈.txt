```
class Solution {
	// 获取两个/之间的值 如果是连续两个/ 则返回空字符串 
	string getString(string s,int& start){
		int len = s.length();
		int cur = start + 1;

		if(s[cur]=='/') {
			start++;
			return "";
		}
		while(s[cur]!='/' && cur<len) cur++;

		string result = s.substr(start+1,cur-start-1);
		start = cur;
		return result;
	}
public:
    string simplifyPath(string path) {
        int len = path.length();
		int cur = -1;
		stack<string> st;
		while(cur<len){
			string str = getString(path,cur);

			if(str=="..") {  // 遇到.. 
				if(!st.empty()) //如果栈不为空 则出栈 
				st.pop();
			}
			else if(str!="/" && str!="." && !str.empty()) st.push(str);  //非这三种情况 则入栈 
		}
		
		if(st.empty()) return "/";
		
		string result = "";
		stack<string> st1;
		while(!st.empty()) st1.push(st.top()), st.pop();  //将栈中的元素倒序 
		
		while(!st1.empty()){  // 生成最终的路径 
			result+="/";
			result+=st1.top();
			st1.pop();
		}        
		return result;
    }
};
```
