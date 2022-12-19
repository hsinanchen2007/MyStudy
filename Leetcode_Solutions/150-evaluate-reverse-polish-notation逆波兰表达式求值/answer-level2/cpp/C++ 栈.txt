思路我就不说了，题解中写的都很好。这里是我实现的代码。供大家参考！
```
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        unordered_map<string,bool> mp;
        mp["+"] = true;
        mp["-"] = true;
        mp["*"] = true;
        mp["/"] = true;
        
        for(int i=0;i<tokens.size();i++){
            if(!mp[tokens[i]]){
                s.push(stoi(tokens[i]));
            }else{
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                
                int res = 0;
                if(tokens[i] == "+"){
                    res = y+x;
                }else if(tokens[i] == "-"){
                    res = y-x;
                }else if(tokens[i] == "*"){
                    res = y*x;
                }else if(tokens[i] == "/"){
                    res = y/x;
                }
                
                s.push(res);
            }
        }
        
        return s.top();
    }
};
```
