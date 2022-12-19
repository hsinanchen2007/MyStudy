### 解题思路
1.记录下标的指针right从0--S.size()-1
2.使用栈，当出现S[right]=='(',就把'('推入栈。
3.当S[right]出现')'时，从栈顶往下看，直到遇到'(',更新并推入这个(  )之间的计算结果，不断循环。
4.由于使用栈想同时记录数值，就定义int型的栈，用0代替'('

![image.png](https://pic.leetcode-cn.com/4ca40d8490e977a750a48a6910c8620c78efc4207d5a93930f203c616d2cb252-image.png)
### 代码

```cpp
class Solution {
public:
    int scoreOfParentheses(string S) {
      int n = S.size();
      if(n==0) return 0;
      int right = 0;
      stack<int> stk;
      int tmp = 0;
      while(right<n){
          if(S[right]=='(') stk.push(0);
          if(S[right]==')'){
              tmp=0;
              if(stk.top()==0){
                  stk.pop();
                  stk.push(1);
                }else{
                  while(stk.top()!=0){
                      tmp+=stk.top();
                      stk.pop();
                      }
                      stk.pop();
                    stk.push(2*tmp);
                    } 
             }
            right++; 
        } 
        int res=0;
        while(!stk.empty()){ res+=stk.top(); stk.pop();}
        return res;
    }
};
```