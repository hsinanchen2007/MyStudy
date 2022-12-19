### 解题思路
1、构建栈，记录左括号的下标li。
2、当出现右括号的时候，记录当前的下标ri。
3、对这之间的字符串进行反转：
```
reverse(s.begin() + li + 1, s.begin() + ri);
```
4、删除左右括号，这里需要注意删除之后会出现size的变动，所以，先删除大的序号是不会造成越界等问题的：
```
s.erase(s.begin() + ri);
s.erase(s.begin() + li);
```
5、当删除括号后，会发现size变小了两位，所以，对当前索引回退两步即可；
6、最终得到完整的反转后的结果。
### 代码

```cpp
class Solution {
public:
    //检测括号，记录下标，然后对字符串进行反转。
    //由于是stack，所以，肯定是最后入栈的序列之间先反转，从里向外，逐层反转
    string reverseParentheses(string s) {
        stack<int> stk;
        for(int i=0;i<s.size();i++)
        {
            if( s[i] == '(')
            {
                stk.push(i);
            }    
            if (s[i] == ')')
            {
                reverse(s.begin() + stk.top() + 1, s.begin() + i);
                //先删除后面的，这样就不会因为前面删除了而造成越界的问题！
                s.erase(s.begin() + i);
                s.erase(s.begin() + stk.top());
                stk.pop();
                //这里是因为删除了两个元素，所以，才会减2.
                i = i - 2;
            }
        }
        return s;
    }
};
```