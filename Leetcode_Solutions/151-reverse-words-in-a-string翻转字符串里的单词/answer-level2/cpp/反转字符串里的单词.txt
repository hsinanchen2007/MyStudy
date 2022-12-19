### 解题思路
此处撰写解题思路
两重循环：
	1.从后往前遍历找到第一个不为' '的字符，记录位置。
	2.然后找到第一个为' '的字符，记录二者位置然后复制给新的字符串。

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
	if (s.length() == 0)  return s;
	for (int i = 0; i < s.length(); i++) {
		if (i == s.length() - 1&&s[i]==' ') return "";
		if (s[i] == ' ') {
			continue;
		}
		else {
			break;
		}
        
		
	}
	string s1;
	for (int i = s.length() - 1; i >= 0; i--) {
		if (s[i] != ' ') {
			int b = i;
			do {
				i--;
				if (i == -1)break;
			} while (s[i] != ' ');
			int a = i;
			string s2(s, a + 1, b-a);
			
			s1 += s2;
			s1 += ' ';
			
			i++;
		}
		

	}
	s1.pop_back();
	return s1;
}
};
```