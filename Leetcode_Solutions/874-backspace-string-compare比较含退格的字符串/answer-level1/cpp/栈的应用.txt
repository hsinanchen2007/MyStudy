### 解题思路
使用两个栈进行模拟。如果是字符则压入栈，如果是‘#’则从栈顶删除一个字符，但是删除前要注意判定栈是否为空。

### 代码

```cpp
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s1,s2;
        for(int i=0;i<S.length();i++){
            if(S[i]!='#'){
                s1.push(S[i]);
            }else if(!s1.empty()){
                s1.pop();
            }
        }
        for(int i=0;i<T.length();i++){
            if(T[i]!='#'){
                s2.push(T[i]);
            }else if(!s2.empty()){
                s2.pop();
            }
        }
        if(s1==s2){
            return true;
        }else
            return false;
    }
};
```