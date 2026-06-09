### 解题思路
对于数字依次压入栈中，当遇到预算符的时候，对栈的前两个数字进行基本的预算，然后压入栈中。
这里唯一需要注意的是**减号和负数**的判定。

### 代码

```cpp
class Solution {
public:
    //基本的入栈出栈应该是
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int first_num, second_num;
        for(int i=0;i<tokens.size();i++)
        {
            if((tokens[i][0] != '+' && tokens[i][0] != '-' 
            && tokens[i][0] !=  '*' && tokens[i][0] != '/') 
            || tokens[i].size() > 1)
            {
                int num = stoi(tokens[i]);
                stk.push(num);
            }
            else
            {
                first_num = stk.top();
                stk.pop();
                second_num = stk.top();
                stk.pop();
                if(tokens[i][0] == '+') stk.push(first_num + second_num);
                if(tokens[i][0] == '-') stk.push(second_num - first_num);
                if(tokens[i][0] == '*') stk.push(first_num * second_num);
                if(tokens[i][0] == '/') stk.push(second_num / first_num);
            }
        }
        return stk.top();
    }
};
```