### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.size();
		string str; 
        //去掉其他多余的东西，只留下英文字符和数字字符
		for(int i=0;i<len;i++){
			if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) 
				str += s[i];
		}
		int len1 = str.size();  //获得最新的字符串的长度
		//将字符串英文全部变成小写字符
		for(int i=0;i<len1;i++){
			if(str[i]>='A' && str[i]<='Z')
				str[i]= str[i] + 'a'-'A';
			else
				str[i] = str[i];
		}
		s.clear();//清空字符串s
		for(int i=len1-1;i>=0;i--){  //反转字符串s
			s += str[i];  
		}
        //进行对比
		for(int i=0;i<len1;i++){
			if(s[i]!=str[i])
				return false;
		}
		return true;
    }
};
```