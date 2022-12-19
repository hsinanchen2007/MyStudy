![image.png](https://pic.leetcode-cn.com/03252adf174481cd582cce785fc5dba45b657d08d2f661bd4f85b6a3cdb5c385-image.png)
```
class Solution {
public:
    int scoreOfParentheses(string S) 
    {
        int num=0;
        stack<int> res;
        for(int i=0;i<S.size();i++)
        {
            if(S[i]=='(') res.push(0);
            else
            {
                if(res.top()==0)
                {
                    res.pop();//将'('出栈，'('用0表示的哦
                    res.push(1);//将结果入栈
                }
                else 
                {
                    int temp=0;
                    while(res.top()!=0)
                    {
                        temp+=res.top();
                        res.pop();
                    }
                    res.pop();
                    res.push(temp*2);  
                }
            }
        }
        
        int result=int(res.top());
        res.pop();
        if(res.empty()) return result;
        else{
            while(!res.empty()) 
            {
                result+=int(res.top());
                res.pop();
            }
            return result;
        }        
    }
};
```
