### 解题思路
执行用时 :
0 ms , 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :6.6 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> mystack;
        int slen = strlen(s.c_str());
        if(slen==0){
            return true;
        }
        for (int i = 0; i< slen;i++){
            if (mystack.empty()){
                mystack.push(s[i]);
                continue;
            }
            char temp = mystack.top();
            if(s[i] == ')' && temp == '('){
                if(!mystack.empty())
                {mystack.pop();}
            }
            else if(s[i]==']'&&temp=='['){
                if(!mystack.empty()){
                    mystack.pop();
                }
                
            }else if(s[i]=='}' &&temp =='{'){
                if(!mystack.empty()){
                    mystack.pop();
                }
            }
            else{
                mystack.push(s[i]);
            }
        }
        return mystack.empty();
        
    }
};
```