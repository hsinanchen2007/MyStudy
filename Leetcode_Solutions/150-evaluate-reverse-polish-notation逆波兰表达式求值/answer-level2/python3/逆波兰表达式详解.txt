一 算法分析与设计
（一）算法分析
根据逆波兰（后缀）表达式计算规则，计算过程应是顺序检查表达式的各项，遇到操作数时，应记录下以备后用；遇到运算符时，首先取出前面最近遇到的两个操作数，并应用这个运算符完成计算，之后保存该中间结果。
由于表达式可以很复杂，不能事先确定需要记录的信息个数，必须用一个缓存结构。再加上这里是后保存的操作数先使用，因此应该用栈来实现。
（二）算法设计
1 用一个集合记录'+', '-', '*', '/'四种运算符，用于后续检验表达式中的各项是否为运算符
定义一个空栈用于记录需要保存的操作数
2 循环遍历表达式各项
如果是操作数，则入栈
如果是运算符，则弹出栈中后两个元素，执行相应计算，并将计算结果入栈
3 若表达式为合法表达式，则最后栈中有且仅有一个元素，此元素即为运算结果

python3实现注意：
python3中"//"为向下取整，当结果小于0时，并不是取得整数部分，因此在除法运算时应使用int(b/a)
二 实现
C++实现
```
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        string operators[] = {"+", "-", "*", "/"};
        set<string> myset(operators, operators+4);
        stack<int> s;        

        int a;
        int b;
        for (auto it = tokens.begin(); it != tokens.end(); it++) {
            if (myset.count(*it) == 0) {
                s.push(stoi(*it));
            }
            else {
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                if (*it == "+") {
                    s.push(b + a);
                }
                else if (*it == "-"){
                    s.push(b - a);
                }
                else if (*it == "*") {
                    s.push(b * a);
                }
                else if (*it == "/") {
                    s.push(b / a);
                }			
            }
        }
        return s.top();
    }
};
```
python3实现

```python3 []
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        operators = {'+', '-', '*', '/'}
        data_stack = []  # use list to instead stack
        for x in tokens:
            if x in operators:
                a = data_stack.pop()
                b = data_stack.pop()
                if x == '+':
                    c = b + a
                elif x == '-':
                    c = b - a
                elif x == '*':
                    c = b * a
                elif x == '/':
                    #c = b // a  # error
                    c = int(b/a)
                else:
                    break
                data_stack.append(c)
            else:
                data_stack.append(int(x))
        return data_stack[-1]
```



