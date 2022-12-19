![Page 3.png](https://pic.leetcode-cn.com/02d1df54214456b2ac174f78599a93f64f655884c43310bc43d193d64907537d-Page%203.png)
```
class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> s;       
        for(char c:S){      
            if(c=='('){     //遇到左括号入栈，用0模拟
                s.push(0);
            }
            else{       //遇到右括号进行判断       
                if(s.top()==0){     //栈顶为0即栈顶为左括号，此时为()的情况，得1分     
                    s.pop();        
                    s.push(1);
                }
                else{       //栈顶不为左括号即为(ABC)的情况，得分为(A+B+C)*2
                    int inScore=0;
                    while(s.top()!=0){
                        inScore+=s.top();
                        s.pop();
                    }
                    s.pop();
                    s.push(inScore*2);
                }
            }
        }
        int score=0;
        while(!s.empty()){      //最后栈内都是分数，没有括号了，求和即可
            score+=s.top();
            s.pop();
        }
        return score;
    }
};
```


