看了一圈代码，发现思路是差不多的，但大部分的代码写得又臭又长。在这里我借助两个栈来模拟计算器。思想如下：
1.从 末尾 开始 往 头部遍历字符串。
（1）遇到 “）”、“+”、“-” 就push 到opors 栈，遇到数字就把该数字完整的表示出来，并push到opands栈；
（2）遇到“（”，开始执行计算，因为括号内的式子优先级最高。从opors 和 opands 中获取操作数和操作符，
并把计算结果push到opands中。直到操作符为“）”为止。
（3）最后对opors进行判空检查，若不为空，则完成剩下的计算。若为空，则return opands.top()

PS:这里从末尾往头部遍历是因为算式的 左结合性。即从左往右计算。
参考代码如下：
```
class Solution {
public:
    int calculate(string s) {
        stack<char> opors;
        stack<int> opands;
        
        for(int i = s.size() -1 ;i >= 0;--i){
            if(s[i] == ' '){
                continue;
            }else if(s[i] == ')' || s[i] == '+' || s[i] == '-'){
                opors.push(s[i]);
            }else if(s[i] == '('){
                while(true){
                    char op = opors.top();
                    opors.pop();
                    if(op == ')'){
                        break;
                    }else{
                        int n1 = opands.top();
                        opands.pop();
                        int n2 = opands.top();
                        opands.pop();
                        int ret = op == '+' ? n1 + n2 : n1 - n2;
                        opands.push(ret);
                    }
                }
                
            }else{
                int num = s[i] - '0';
                int base = 1;
                for(int j = i-1;j>=0;--j){
                    if(isalnum(s[j])){
                        base *= 10;
                        num += (s[j] - '0') * base;
                        i = j;
                    }else{
                        i = j + 1;
                        break;
                    }
                }
                opands.push(num);
            }
        }
        
        while(!opors.empty()){
            char op = opors.top();
            opors.pop();
            int n1 = opands.top();
            opands.pop();
            int n2 = opands.top();
            opands.pop();
            int ret = op == '+' ? n1 + n2 : n1 - n2;
            opands.push(ret);
        }
        
        return opands.top();
        
    }
};
```
