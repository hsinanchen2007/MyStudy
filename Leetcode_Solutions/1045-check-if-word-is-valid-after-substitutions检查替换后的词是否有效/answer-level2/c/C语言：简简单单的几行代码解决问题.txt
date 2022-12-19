![QQ截图20190721075342.png](https://pic.leetcode-cn.com/608654129e736823049ed5b19b9bac7b4ac7c61c7a224de7f0f87235fa45dee7-QQ%E6%88%AA%E5%9B%BE20190721075342.png)
- 题目说X+Y，但是这道题目并没有体现这个特点。
- 仅仅是把"abc"往"abc"中的任意一个位置插入，只要符合插入情况就可以了
- 如：aabcbc   ababcc  abcabc

**第一种：计数法**
```
bool isValid(char * S){
    if (S == NULL || S[0] == '\0') return true;
    int char_num[128];
    char_num['a'] = char_num['b'] = char_num['c'] = 0;
    for (int i = 0; S[i]; ++i) {
        if ((S[i] == 'a' && S[i+1] == 'c') ||                  //防止：abacbc
            (S[i] == 'b' && S[i+1] == 'b'))     return false;  //防止：aabbcc
        
        ++char_num[S[i]];
        if ((char_num['a'] < char_num['b']) ||                 //b的数量不能大于a
            (char_num['b'] < char_num['c']) ||                 //c的数量不能大于b
            (char_num['a'] < char_num['c']))    return false;  //c的数量不能大于a
    }

    return ((char_num['a'] == char_num['b'])&&(char_num['b'] == char_num['c'])); //abc数量必须相等
}
```
**第二种：使用栈**
- C++ 描述，一次遍历使用一个栈
- 当遇到字符a时,直接入栈
- 当遇到字符b时，检查栈顶是否为字符a ,如果是将b入栈，如果不是返回false；
- 当遇到字符c时，检查栈顶是否为字符b,如果是将c入栈,（再将栈顶的cba弹出）如果不是返回false
- 最后判断栈是否为空即可
```
class Solution {
public:
    bool isValid(string S) {
        stack<char> s;
        for(char c:S){
            if     (c == 'b' && (s.empty() || (s.top() != 'a'))) return false;
            else if(c == 'c' && (s.empty() || (s.top() != 'b'))) return false;
            s.push(c);
            if (c == 'c'){
                s.pop();s.pop();s.pop();
            }
        }
        return s.empty();
    }
};
```
