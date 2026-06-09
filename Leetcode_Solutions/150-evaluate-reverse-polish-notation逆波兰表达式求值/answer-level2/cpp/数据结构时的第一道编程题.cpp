

```
class Solution {
public:
    string helper(int a, int b, string t){
        int sum=0;
        switch(t[0]){
            case '+':
                sum=a+b;break;
            case '-':
                sum=a-b;break;
            case '*':
                sum=a*b;break;
            case '/':
                sum=a/b;break;
        }
        return to_string(sum);
    }
    bool isop(string t){
        if(t=="*"||t=="/"||t=="+"||t=="-")return true;
        return false;
    }
    int evalRPN(vector<string>& tokens) {
        stack<string>Stack;
        for(int i=0;i<tokens.size();i++){
            if(!isop(tokens[i])){
                Stack.push(tokens[i]);
            }else{
                string a=Stack.top();
                Stack.pop();
                string b=Stack.top();
                Stack.pop();
                Stack.push(helper(stoi(b),stoi(a),tokens[i]));
            }
        }
        return stoi(Stack.top());
    }
};
```
