### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string removeOuterParentheses(string S) {
    stack<char> myStack;

    string tmp = "";
    int left = 0;
    int right = 0;
    for (int i = 0; i < S.size(); ++i) {
        if(S[i] == '('){
            myStack.push('(');
        }
        else{
            myStack.pop();
            if(myStack.empty()){
                if(left + 1 < right - 1){
                    tmp += S.substr(left + 1, right - left - 1);
                }
                left = right + 1;
            }
        }
        right++;
    }
    return tmp;
}
};
```