使用栈模拟行星碰撞，对 asteroids 进行顺序遍历或者逆序遍历都是可以的，结果都是由最终的栈生成 vector 进行返回。如果出栈次序的数据跟结果需要的次序相反，可以根据栈的大小先生成 vector，再通过下标访问得到结果。

***Talk is cheap. Show me the code.***

```
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        auto i = asteroids.size();
        for (; i > 0; i--) {
            int e = asteroids[i-1];
            while (!stk.empty() && stk.top() < 0 && e > 0) {
                if (stk.top() + e == 0) e = 0;
                else if (stk.top() + e < 0) e = stk.top();
                else ;
                stk.pop();
            }
            if (e != 0) {
                stk.push(e);
            }
        }
        vector<int> result(stk.size());
        while (!stk.empty()) {
            result[i++] = (stk.top());
            stk.pop();
        }
        return result;
    }
};
```
