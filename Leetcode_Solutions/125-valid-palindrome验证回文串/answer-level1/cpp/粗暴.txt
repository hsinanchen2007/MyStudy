class Solution {
```
public:
    bool isPalindrome(string s) {
        string t;
        int i;
        for(i=0;i<s.size();i++){//将s转换为小写字母和数字字符
        	if((s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9'))
        		t.push_back(s[i]);
        	else if(s[i]>='A'&&s[i]<='Z')
        		t.push_back(s[i]+32);
		}
        for(int i=0;i<t.size();i++){//前后比较
        	if(t[i]!=t[t.size()-i-1])
        		return 0;
		}
		return 1;
    }
```
};