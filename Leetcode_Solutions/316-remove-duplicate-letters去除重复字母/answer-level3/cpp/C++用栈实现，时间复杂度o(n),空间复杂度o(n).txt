### 解题思路
构造一个栈，遍历字符串，用一个数组记录当前已有的字母。
首先若当前字母已经被记录过则跳过，
若当前字母大于栈顶字母则放入，
否则若在当前字母后面的子串中还有栈顶字母的话则

### 代码
#include <iostream>
#include <stack>
#include <algorithm>
#include <stdio.h>
using namespace std;

class Solution {
public:
	string removeDuplicateLetters(string s){
		stack<char> charStack;
		// 用一个数组记录26个字母最后在s中出现的位置
		int lastAppear[26] = {0};
		for(int i = 0; i < s.size(); ++i){
			lastAppear[s[i] - 'a'] = i;
		}

		// 用一个数组记录26个字母是否已经被使用过
		int visited[26] = {0};
		for(int i = 0; i < s.size(); i++){
			char c = s[i];
			// 如果当前字母已经被使用，跳过
			if(visited[c - 'a']){
				continue;
			}
			// 如果当前子串是空的或子串中所有字母都当前字母小
			if(charStack.empty() or c>charStack.top()){
                // 使用当前字母
				charStack.push(c);
			}else{ //如果子串中有比当前字母大的字母
			    // 弃用子串的所有比当前字母大且在源串S的更靠后的位置会出现在的字母
				while(!charStack.empty() and charStack.top() > c and lastAppear[charStack.top()-'a']>i){
					visited[charStack.top() - 'a'] = 0;
					charStack.pop();
				}
                // 使用当前字母
				charStack.push(c);
			}
			// 把当前字母记录为已使用
			visited[c - 'a'] = 1;
		}
		string result = "";
		while(!charStack.empty()){
			result += charStack.top();
			charStack.pop();
		}
		// 翻转字符串
		reverse(result.begin(), result.end());
		return result;
	}
};

// 测试
int main()
{
	Solution s;
	string str= "abefcdabbcf";
	cout<<s.removeDuplicateLetters(str);
}
