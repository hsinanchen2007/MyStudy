![image.png](https://pic.leetcode-cn.com/fde3f6f113fe99b45069b688eded43361233ee713da3c9e0141c3f0b7656b8bd-image.png)


```
/*题目：逆波兰表达式
 * 作者：曹永熙
 * 时间：2020.1.31
 * 知识点：栈
 */

class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        if(tokens.size()==1) return stoi(tokens[0]);
        //stack<string> RPN;
        stack<int> RPN;
        RPN.push(stoi(tokens[0]));
        RPN.push(stoi(tokens[1]));

        int temp1,temp2;

        int index = 2;
        while(true){
           
            if(isNum(tokens[index])) {RPN.push(stoi(tokens[index]));}
            else{
                temp2 = RPN.top();
                RPN.pop();
                temp1 = RPN.top();
                RPN.pop();
                switch (whatChar(tokens[index])) {
                    case 1:
                        RPN.push((int)temp1 + temp2);
                        break;
                    case 2:
                        RPN.push((int)temp1 - temp2);
                        break;
                    case 3:
                        RPN.push((int)temp1 * temp2);
                        break;
                    case 4:
                        RPN.push((int)(temp1 / temp2));
                        break;
                }
            }
            
            index++; if(index==tokens.size()) break;

        }
        
        return RPN.top();

    }

           
    bool isNum(string unknown){
        return !(unknown=="+"||unknown=="-"||unknown=="*"||unknown=="/");
    }

    // 逆波兰表达式中只有4种运算，加减乘除
    // 规定返回值1为加，2为减，3为乘，4为除
    int whatChar(string unknown){
        if (unknown=="+") {
                return 1;
        }else if(unknown=="-"){
                return 2;
        }else if(unknown=="*"){
                return 3;
        }else if(unknown=="/"){
                return 4;
        }
        return 0;
    }
};
```
