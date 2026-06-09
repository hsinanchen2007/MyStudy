使用栈+哨兵
1. 栈里存放括号的索引，栈顶为哨兵（意为第一个左括号的索引-1），预先放置-1为初始哨兵。
2. 遍历s, 如果是左括号，将索引入栈
3. 如果是右括号，先pop掉栈顶，然后判断栈是否为空，
     -  如果为空，说明前面已经匹配完，将这个右括号的索引作为新的哨兵入栈
     -  如果不为空， 则 `i-res_stack.top()`为新的匹配括号的长度，和之前的长度取最大值。 


```
class Solution {
public:
    int longestValidParentheses(string s) {
        int leng = s.size();
        int res = 0;
        stack<int> res_stack;
        res_stack.push(-1);
        for(int i = 0;i < leng;i++){
            if(s[i] == '('){
                res_stack.push(i);
            }else{
                res_stack.pop();
                if(res_stack.size() == 0){
                    res_stack.push(i);
                }else{
                    res = res > (i-res_stack.top()) ? res : (i-res_stack.top());
                }
            }
        }
        return res;
    }
};
```
