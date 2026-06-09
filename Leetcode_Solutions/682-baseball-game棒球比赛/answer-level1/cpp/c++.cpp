### 解题思路
执行用时 :4 ms, 在所有 cpp 提交中击败了96.62%的用户
内存消耗 :9.3 MB, 在所有 cpp 提交中击败了83.16%的用户

标识分类判断得出实际分数存于分数栈中，累计得出总和
### 代码

```cpp
class Solution {
public:
    int calPoints(vector<string>& ops) {
        int res = 0,plusRes = 0,last1 = 0;
        std::stack<int> points;
        for(auto str : ops)
        {
            if(str == "+")
            {
                last1 = points.top();
                points.pop();
                plusRes = last1 + points.top();
                points.push(last1);
                points.push(plusRes);
            }
            else if(str == "D")
            {
                points.push(points.top() * 2);
            }
           else if(str == "C")
            {
                points.pop();
            }
            else    //整数情况
            {
                points.push(atoi(str.c_str()));
            }
        }
        while(!points.empty())
        {
            res  += points.top(); 
            points.pop();
        }
        return res;
    }
};
```