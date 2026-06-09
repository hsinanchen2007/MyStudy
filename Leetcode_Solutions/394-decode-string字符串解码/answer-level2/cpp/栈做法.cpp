按照[]来划分，没碰到]时将元素进栈，碰到]时，将栈中[之前的元素都出栈拼在一起，然后将拼起来的字符串重复对应的k次压入栈中
最后把栈里的元素拼起来即可。
```c++
class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        stack<string>stk;
        string res="";
        if(!n)return res;
        for(int i=0;i<n;i++){
            if(s[i]!=']'){
                stk.push(string(1,s[i]));
            }
            else {
                string alpha="";
                while(!stk.empty() && stk.top()!="["){
                    alpha+=stk.top(),stk.pop();
                }
                stk.pop();
                string num ="";
                while(!stk.empty() && stk.top()>="0" && stk.top()<="9"){
                    num+=stk.top();
                    stk.pop();
                }
                reverse(num.begin(),num.end());
                int a = atoi(num.c_str());
                while(a--)stk.push(alpha);
            }
        }
        while(!stk.empty()){
            res+=stk.top();
            stk.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }   
};
```