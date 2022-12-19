这个代码不用解释也能看懂吧，哈哈~~~~
还是啰嗦一下吧，注意点：
判断是否数字时长度先判断比较快，长度为一的判断第一个字符是否为数字；
stoi函数与ctoi不同，ctoi需要转换为c_str先，直接使用stoi函数；
栈的top函数返回的是引用，可以直接计算，不用弹出后计算完压入。
```
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> tokStack;
        int tmp;
        for(auto &token:tokens){
            if(token.size() > 1 || (token[0] >= '0' &&  token[0] <= '9')) tokStack.push(stoi(token));
            else{
                tmp = tokStack.top();
                tokStack.pop();
                switch(token[0]){
                    case '+': tokStack.top() += tmp;break;
                    case '-': tokStack.top() -= tmp;break;
                    case '*': tokStack.top() *= tmp;break;
                    case '/': tokStack.top() /= tmp;break;
                    default:break;
                }
            }
        }
        return tokStack.top();
    }
};          
```
