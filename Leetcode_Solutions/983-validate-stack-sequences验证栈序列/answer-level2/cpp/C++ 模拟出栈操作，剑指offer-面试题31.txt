建立两个栈进行模拟出栈操作，先将 ```popped``` 倒序全部压入栈```s2```中，再针对 ```pushed``` 进行顺序逐个压入栈```s1```，并在循环内部判断，该压入元素即 ```s1.top()```是否等于 ```s2.top()```，在此需要采用```while```循环判断,若在 ```while``` 内部栈 ```s1```为空，应当直接 ```break``` 跳出 ```while``` 循环，否则再进行```while```循环判断```s1.top()```出错。当 ```for``` 循环结束后意味着所有元素都已经完成了压栈操作，若栈 s1 为空，则模拟出栈成功，否则失败，在此直接返回``` s1.empty()```即可，由于```pushed```是 ```popped```的排列，返回```s1.empty()```也可。

```cpp
// 执行用时 :8 ms, 在所有 C++ 提交中击败了93.62%的用户
// 内存消耗 :9.6 MB, 在所有 C++ 提交中击败了5.30%的用户

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s1, s2;
        for (int i = popped.size() - 1; i >= 0; --i) 
            s2.push(popped[i]);
        for (int i = 0; i < pushed.size(); ++i) {
            s1.push(pushed[i]);
            while (s2.top() == s1.top()) { 
                s1.pop();
                s2.pop();
                if (s1.empty()) 
                    break;
            }
        }
        return s1.empty();
    }
};
```
