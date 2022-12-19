### 解题思路
![image.png](https://pic.leetcode-cn.com/05d8457b7620579175db7630e6357a11a4ebd2182b26e5d1f24fcbd1d7d446b8-image.png)

### 代码

```cpp
class Solution {
public:
    int calPoints(vector<string>& ops) {
        int ans = 0, a = 0, b = 0, c = 0;
        stack<int> stacks;
        stringstream ss;  //将字符串变为数字
        for(int i = 0; i < ops.size(); i ++)
        {
            if(ops[i] == "C")  //如果为“C”，结果减去上一轮的得分，并将上一轮的得分删除
            {
                ans -= stacks.top();
                stacks.pop();
            }
            else if(ops[i] == "D")  //如果为“D”，本轮得分为上一轮的分的2倍，结果加上本轮得分，并将本轮得分入栈
            {
                ans += 2 * stacks.top();
                stacks.push(2 * stacks.top());
            }
            else if(ops[i] == "+")  //如果为“+”，本轮得分为前两轮得分之和，结果加上本轮得分，并将本轮得分入栈
            {
                a = stacks.top();
                stacks.pop();
                b = stacks.top();
                stacks.push(a);
                stacks.push(a + b);
                ans += (a + b);
            }
            else  //如果为数字的话，将字符串变为数字，作为本轮得分入栈，结果相加
            {
                ss.clear();
                ss << ops[i];
                ss >> c;
                stacks.push(c);
                ans += c;
            }
        }
        return ans;
    }
};
```