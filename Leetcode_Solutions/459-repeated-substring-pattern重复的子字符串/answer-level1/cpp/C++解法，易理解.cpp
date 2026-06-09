如有疏漏，请指正
```
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if(s.size()<=1) return false;
        string str;   //样板子串长度从1开始
	    int count=1;  //子串长度
	    for(; count<=(s.size()+1)/2; count++){
		    if(s.size()%count!=0) continue;  //如果不满足整除关系，那此时的str一定不满足要求
		    str=s.substr(0,count);  //截取样板子串
		    int i=count; //从样板子串后开始
		    for(; i<s.size(); i+=count){
		    	string temp = s.substr(i,count); //以样板子串的长度为步长截取后续子串
		        if(temp!=str) break;  //出现不匹配
		    }
		    if(i==s.size()) return true;
	    }
	return false;
    }
};

