1. 遍历出栈序列，如果出栈序列合法，遍历到的符号X应该在栈的顶端，或者在入栈前的队列中。
2. 如果在栈顶，出栈这个符号X。
3. 不在栈顶时，遍历队列，寻找这个符号X，并将X前的符号入栈。
4. 队列已经为空还没找到X，则出栈序列不合法。
5. 验证完出栈序列后，判断入栈前的队列是否为空。
```
class Solution {
public:
    bool validateStackSequences(const vector<int>& pushed, const vector<int>& popped) {
        stack<int> sk;
        auto first = pushed.cbegin();
        for (const auto ch : popped) {
            if (!sk.empty() && sk.top() == ch) {
                sk.pop();
            } else {
                while (first != pushed.cend() && *first != ch)
                    sk.push(*first++);
                if (first == pushed.cend()) return false;
                else first++;
            }
        }
        return first == pushed.cend();
    }
};
```
