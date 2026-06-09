思路：

    利用堆栈后进先出的特点，遇到左括号就压入栈内，遇到右括号时，判断右括号与栈顶元素是否匹配（右括
    号不能进栈）。若匹配则弹出栈顶的左括号，继续遍历。不匹配则返回false。直到遍历结束后，栈内的左括
    号应完全弹出才返回true。
    

代码块：
```
class Solution{
	public:
		bool isValid(string s) {
        stack<char> sta;
        sta.push('~');
        if(s.length()%2) return false;
        for(int i=0;i<s.length();i++){
        	if(isLeft(s[i])){
        		sta.push(s[i]);
        		continue;
			}
			if(!isLeft(s[i])){
				if(Match(sta.top(),s[i]))
				sta.pop();
				else return false;
			}
		}
		if(sta.size()==1)
		return true;
		return false;
    }
    	bool isLeft(char a){
    	if(a=='('||a=='['||a=='{')
    	return true;
    	return false;
	}
		bool Match(char a,char b){       //匹配确实很麻烦。。应该有别的方法。
			if(a=='('&&b==')')
			return true;
			if(a=='['&&b==']')
			return true;
			if(a=='{'&&b=='}')
			return true;
			return false;
		}
};
```
