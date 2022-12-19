### 解题思路
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :8.9 MB, 在所有 C++ 提交中击败了5.43%的用户

### 代码
```
class Solution {
public:
    bool backspaceCompare(string s, string t){
	stack<char>a;
	stack<char>b;
	for(int i=0;i<s.size();i++){
		if(s[i]=='#'&&!a.empty()){
			a.pop();
		}
		else if(s[i]=='#'&&a.empty())
			continue;	
		else{
			a.push(s[i]);
		}
	}
	for(int i=0;i<t.size();i++){
		if(t[i]=='#'&&!b.empty()){
			 b.pop();
		}	
		else if(t[i]=='#'&&b.empty())
			continue;
		else{
			b.push(t[i]);
		}
	}
			
	string ans_a="";
	string ans_b="";
	while(!a.empty()){
		ans_a+=a.top();
		a.pop(); 
	}
	while(!b.empty()){
		ans_b+=b.top();
		b.pop(); 
	}
	if(ans_a==ans_b)
		return 1;
	else return 0;
}
};
```
```cpp

```