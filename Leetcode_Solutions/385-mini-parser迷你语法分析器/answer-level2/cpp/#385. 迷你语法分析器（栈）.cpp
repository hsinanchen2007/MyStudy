思路不难，最初用的是 stack<NestedInteger> ，结果时间和空间都只超过 5% 左右，懵了。问题出在执行 push 操作的时候执行了类拷贝成员函数，不知道 NestedInteger 拷贝是怎么实现的，特别费时。优化方式是使用 stack<NestedInteger*>，优化后内存消耗击败 100%，用时在 24ms 以内。

***Talk is cheap. Show me the code.***

```
NestedInteger deserialize(string s) {
    stack<NestedInteger*> stk;
    string numStr;
    for (char &c : s) {
        if (c == '[') {
            NestedInteger *res = new NestedInteger();
            stk.push(res);
        } else if (c == '-' || isdigit(c)) {
            if (stk.empty()) return NestedInteger(stoi(s));
            else numStr.push_back(c);
        } else if (c == ',') {
            if (!numStr.empty()) {
                stk.top()->add(NestedInteger(stoi(numStr)));
                numStr = "";
            }
        } else {
            if (!numStr.empty()) {
                stk.top()->add(NestedInteger(stoi(numStr)));
                numStr = "";
            }
            NestedInteger *res = stk.top();
            stk.pop();
            if (stk.empty()) {
                return *res;
            } else {
                stk.top()->add(*res);
            }
        }
    }
    return NestedInteger();
}
```
![1115.png](https://pic.leetcode-cn.com/8423c836c41af1a95119ca619cbee70f5b08933c0ffa4ae986a5cb89186c9417-1115.png)



