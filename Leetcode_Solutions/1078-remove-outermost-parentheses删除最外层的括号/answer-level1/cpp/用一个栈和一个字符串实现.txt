
用一个栈来实现。

​	如果栈空：入栈。

​	如果栈不空：判断。如果是`(`则push`(`,把`(`加到`res`如果是`)`把栈顶的元素`pop`出来 然后判断栈是否为空。栈空，则不加入`res`，否则加入`res`

```
class Solution {
public:
    string removeOuterParentheses(string S) {
        string res="";
        stack<char> mystack;
        for(int i=0;i<S.size();i++){
            if(mystack.empty()){
                mystack.push(S[i]);
            }
            else{
                if(S[i]=='('){
                    res+=S[i];
                    mystack.push(S[i]);
                }
                else if(S[i]==')'){
                    mystack.pop();
                    if(!mystack.empty())
                        res+=S[i];
                }
            }
        }
        return res;
    }
};
```
