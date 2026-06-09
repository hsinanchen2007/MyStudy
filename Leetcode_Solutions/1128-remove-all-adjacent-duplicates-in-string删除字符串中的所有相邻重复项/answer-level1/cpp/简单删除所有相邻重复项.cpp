![批注 2019-12-17 194054.png](https://pic.leetcode-cn.com/c889a0b97226253799cc92de6b36fcc25385bdd05acae9a22373ba8eef64973c-%E6%89%B9%E6%B3%A8%202019-12-17%20194054.png)

### 解题思路
1.使用最小内存进行删除操作
2.首先使用一个栈用来存储没有相邻重复项的字符串
3.然后再使用一个栈将其反向存储
4.最后再反向存储进字符串
5.通过三次遍历，一次正向遍历，两次反向遍历，换取更小的空间来实现删除所有相邻重复项的操作

### 代码

```cpp
class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> s;
        int Si = 0;
        while(S[Si])
        {
            if(!s.empty() && s.top() == S[Si])
                s.pop();
            else
                s.push(S[Si]);
            ++Si;
        }
        stack<char> s0;
        while(!s.empty())
        {
            s0.push(s.top());
            s.pop();
        }
        string S0 = "";
        while(!s0.empty())
        {
            S0 += s0.top();
            s0.pop();
        }
        return S0;
    }
};
```