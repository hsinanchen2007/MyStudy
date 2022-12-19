### 解题思路
    打卡学习 ~ ~ ~
### 代码

```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> res(n);
        stack<int> s;
        for(int i = 0;i < n;i++){
            while(!s.empty() && T[s.top()] < T[i]) {
                res[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()) {res[s.top()] = 0;s.pop();}
        return res;
    }
};
```