要求：
1. 输入字符串的数学表达式；
2. 可以计算包括 + - * / 四种运算；
3. 输入的字符串可能包含空格；
```
class Solution {
public:
    int calculate(std::string s) {
        //void compute(std::stack<int> &number_stack, std::stack<char> &operation_stack);
        static const int state_begin=0;
        static const int number_state=1;
        static const int operation_state=2; //case作用
        std::stack<int> number_stack;
        std::stack<char> operation_stack;
        long  number = 0;   //计算number时，可能出现计算总和超过int类型范围，所以使用long类型
        int state=state_begin;
        int compute_flag=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                continue;
            }
            switch(state){
                case state_begin:
                    if(s[i] >= '0' && s[i] <= '9'){
                        state=number_state;
                    }
                    else{
                        state=operation_state;
                    }
                    i--;
                    break;
                case number_state:
                    if(s[i] >= '0' && s[i] <= '9'){
                        number= number * 10 + s[i]-'0';
                    }
                    else{
                        number_stack.push(number);
                        if(compute_flag==1){
                            compute(number_stack,operation_stack);
                        }
                        number=0;
                        i--;
                        state=operation_state;
                    }
                    break;
                case operation_state:
                    if(s[i]=='+'|| s[i]=='-'){
                        operation_stack.push(s[i]);
                        compute_flag=1;
                    }
                    else if(s[i]=='('){
                        state=number_state;
                        compute_flag=0;
                    }
                    else if(s[i]==')'){
                        compute(number_stack, operation_stack);
                    }
                    else if(s[i]>='0'&&s[i]<='9'){
                        state=number_state;
                        i--;
                    }
                    break;
            }
        }
        if(number!=0){
            number_stack.push(number);
            compute(number_stack,operation_stack);            
        }
        if(number==0&&number_stack.empty()){
            return 0;
        }
        return number_stack.top();
    }
void compute(std::stack<int> &number_stack, std::stack<char> &operation_stack){
    if(number_stack.size()<2){
        return ;
    }
    int num2=number_stack.top();
    number_stack.pop();
    int num1=number_stack.top();
    number_stack.pop();
    if(operation_stack.top()=='+'){
        number_stack.push(num1+num2);
    }
    else if(operation_stack.top()=='-'){
        number_stack.push(num1-num2);
    }
    operation_stack.pop();
}

};
```
