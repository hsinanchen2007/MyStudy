使用两个栈，一个用来存储操作符（opr），一个用来存储数字（num），在遍历时：
1. 遇到加、减、乘、除、左括号，放进opr里面；
2. 遇到数字，把完整的数字记下来，然后看opr的顶部如果是乘或除的话，就作一次运算，结果还是放进num栈里面；
3. 遇到右括号，因为第二步可以保证乘除已经实现运算完了，所以左右括号区间的opr里面只剩加和减了，把区间内的num按opr是加还是减求和即可，结果依然放进num中；
做完以上遍历后，opr里面应该还会剩一堆加减符号，最后一步还是按类似步骤三的方法求一遍和，就能得到答案了。
有一个小细节，就是可能会遇到开头是“-”的表达式，例如“-1+1”，我们可以事先在num栈里面放一个0以应对这种情况（可以推一下，事先放一个0是不会影响到正常情况的）。

``` c++ []
class Solution {
public:
    int calculate(string s) {
        stack<char> opr;
        stack<int> num;
        num.push(0);
        int idx = 0;
        while(idx < s.size()){
            if(s[idx] == ' ')
                ++idx;
            else if(s[idx] == '(' || s[idx] == '+' || s[idx] == '-' || s[idx] == '*' || s[idx] == '/'){
                opr.push(s[idx]);
                ++idx;
            }
            else if(s[idx] == ')'){
                int sum = 0;
                while(opr.top() != '('){
                    char op = opr.top();
                    opr.pop();
                    int n = num.top();
                    num.pop();
                    sum += op=='+'? n: -n;
                }
                sum += num.top();
                num.pop();
                num.push(sum);
                opr.pop();
                ++idx;
            }
            else{
                string tmp = "";
                while(idx < s.size() && s[idx] >= '0' && s[idx] <= '9'){
                    tmp.push_back(s[idx]);
                    ++idx;
                }
                num.push(stoi(tmp));
                if(!opr.empty() && (opr.top() == '*' || opr.top() == '/')){
                    char op = opr.top();
                    opr.pop();
                    int second = num.top();
                    num.pop();
                    int first = num.top();
                    num.pop();
                    num.push(op=='*'? first*second: first/second);
                }
            }
        }
        // 最后opr里面只剩+和-两种符号了，所以就把他们加起来即可
        int sum = 0;
        while(!opr.empty()){
            char op = opr.top();
            opr.pop();
            int n = num.top();
            num.pop();
            sum += op=='+'? n: -n;
        }
        
        return sum + num.top();
    }
};
```
