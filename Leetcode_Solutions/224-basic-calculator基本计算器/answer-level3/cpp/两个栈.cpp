### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int calculate(string s) {
        stack<char> oper;
        stack<int> num;
        int idx = 0;
        int n = s.size();
        
        num.push(0);
        while(idx<n)
        {
            char c = s[idx];
            if(c==' ')
            {
                idx++;
            }
            else if(c=='('||c=='+'||c=='-'||c=='*'||c=='/')
            {
                oper.push(c);
                idx++;
            }
            else if(c == ')')
            {
                int sum = 0;                
                while(oper.top() != '(')
                {
                    char tmp = oper.top();
                    oper.pop();
                    int val = num.top();
                    num.pop();
                    sum += (tmp == '+' ? val: -val);
                }
                sum += num.top();
                num.pop();
                num.push(sum);
                oper.pop();
                idx++;                
            }
            else//为数字的情况
            {
                string tmp = "";
                while(idx<n && s[idx]>='0'&&s[idx]<='9')
                {
                    tmp.push_back(s[idx++]);
                }
                num.push(stoi(tmp));
                if(!oper.empty() && (oper.top() == '*' || oper.top() == '/'))
                {
                    char op = oper.top();
                    oper.pop();
                    int second = num.top();
                    num.pop();
                    int first = num.top();
                    num.pop();
                    num.push(op=='*'?first*second:first/second);
                }
            }
        }
        // 最后opr里面只剩+和-两种符号了，所以就把他们加起来即可
        int sum = 0;
        while(!oper.empty()){
            char op = oper.top();
            oper.pop();
            int n = num.top();
            num.pop();
            sum += op=='+'? n: -n;
        }
        
        return sum + num.top();
    }
};
```