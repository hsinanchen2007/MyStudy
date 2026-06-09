1.C++ 解题 
2. 不求性能最优, 但求简介易懂

```
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> values;
        for(auto& str : tokens){
            if(str == "*" ||str == "/" ||str == "+" ||str == "-")
                resolve(values,str);
            else
                values.push(atoi(str.c_str())); //string to int
        }
        return values.top(); 
    }
    void resolve(stack <int>& num_stack,string operation)
    {
        int obj1,obj2;
        
        obj2 = num_stack.top();
        num_stack.pop();
        obj1 = num_stack.top();
        num_stack.pop();
        
        num_stack.push(calc(obj1,obj2,operation));
    }
    int calc(int obj1,int obj2,string operation)
    {
        switch(operation[0])
        {
            case '+':
                    obj1 = obj1 + obj2;
                    break;
            case '-':
                    obj1 = obj1 - obj2;
                    break;
            case '*':
                    obj1 = obj1 * obj2;
                    break;
            case '/':
                    obj1 = obj1 / obj2;
                    break;
        }
        return obj1;
    }
};
```