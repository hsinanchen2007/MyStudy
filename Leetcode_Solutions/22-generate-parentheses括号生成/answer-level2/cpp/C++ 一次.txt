### 解题思路
深度优先搜索，分为添加“（“ 和 ”）“的两个分支；

退出循环条件：
b>a||a>n||b>n 不符合定义而退出循环

查找目标：
（a==n&&b==n） 符合条件，且达到个数 添加
a 左括号个数，b右括号个数


### 代码

```cpp
class Solution {
public:
	vector<string> temp;
	void build(int n,string &str,int a,int b){
		if(b>a||b>n||a>n) return;
		if(a==n&&b==n){
			temp.push_back(str);return;
		}
		string str1=str+"(";
		string str2=str+")";
		build(n,str1,a+1,b);
		build(n,str2,a,b+1);
	}
    vector<string> generateParenthesis(int n) {
        string str;
		temp.clear();
		build(n,str,0,0);
		return temp;
    }
};
```