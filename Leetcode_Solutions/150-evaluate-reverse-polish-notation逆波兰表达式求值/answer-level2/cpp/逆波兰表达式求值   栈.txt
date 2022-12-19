容易出错的地方：stack.pop() 和stack.top()搞混淆
switch('')里面是字符

### 代码

```cpp
class Solution {
public:
    void helper(stack<int>& mystack, string it)
    {
        int right = mystack.top();
        mystack.pop();
        int left = mystack.top();
        mystack.pop();
        int result = 0;
        switch(it[0]){ //这里要取字符
            case '+' :
                result = left + right;
                break;
            case '-' :
                result = left - right;
                break;
            case '*' :
                result = left * right;
                break;
            case '/' :
                result = left / right;
                break;
        }
        mystack.push(result);
    }



    int evalRPN(vector<string>& tokens) {
        stack<int>mystack;
        int result;
        for (string it : tokens){
            if (it == "+" || it == "-" || it == "*" || it == "/") {
                helper(mystack, it);
            }
            else {
                mystack.push(stoi(it));
            }
        }
        return mystack.top();
    }
};
```