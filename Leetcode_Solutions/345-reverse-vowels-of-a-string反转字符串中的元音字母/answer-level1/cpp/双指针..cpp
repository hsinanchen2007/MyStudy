### 解题思路
此处撰写解题思路
我是栽了这道题了..
他nn的,,这么简单的一题,
不过暴露出了审题的缺陷.

### 代码

```cpp
class Solution {
public:
   bool judge(char s)
{
	if(s=='a'||s=='e'||s=='i'||s=='o'||s=='u') return true;
	if(s=='A'||s=='E'||s=='I'||s=='O'||s=='U') return true;
	return false;
}
string reverseVowels(string s) 
{
	 int len=s.length();
        string t="";
	 for(int i=0;i<len;i++)
	 {
	 	if(judge(s[i])) {
	 		t+=s[i],s[i]=' ';
		 }
		else if(s[i]==' ') s[i]='\002';
		else ;
	 }
	 int ind=t.length()-1;
    
	 for(int i=0;i<len&&ind>=0;i++)
	 {
	 	if(s[i]==' ') s[i]=t[ind],ind--;
	 	else ;
	 }
    for(int i=0;i<len;i++) if(s[i]=='\002') s[i]=' ';
	 return s;
}
};
```