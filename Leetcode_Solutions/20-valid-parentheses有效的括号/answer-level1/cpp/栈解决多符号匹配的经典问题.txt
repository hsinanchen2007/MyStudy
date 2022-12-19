执行结果

![捕获.PNG](https://pic.leetcode-cn.com/37740d4e95252d95f6aac9f976115bd3237679ef828e82b7af0c6596e623bc07-%E6%8D%95%E8%8E%B7.PNG)

复杂度分析
```
    时间复杂度：O(n)，因为我们一次只遍历给定的字符串中的一个字符并在栈上进行 O(1) 的推入和弹出操作。
    空间复杂度：O(n)，当我们将所有的开括号都推到栈上时以及在最糟糕的情况下，我们最终要把所有括号推到栈上。
```
### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2) return false;
        vector<char> vecStack;
        char c;
        for(auto i : s) {
            if(i == '}' || i == ')' || i== ']') {
                if (!vecStack.empty()) c = vecStack[vecStack.size()-1];
                else return false;
                if(i == '}' && c != '{') return false;
                if(i == ')' && c != '(') return false;
                if(i == ']' && c != '[') return false;
                vecStack.pop_back();
            }
            else vecStack.push_back(i);
        }
        return vecStack.empty();
    }
};
```