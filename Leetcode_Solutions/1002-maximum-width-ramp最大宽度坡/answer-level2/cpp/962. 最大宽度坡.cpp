### 解题思路
先从头部开始建立一个单调栈，再从尾部开始排查。

### 代码

```cpp
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        stack<int> s;
        
        int res = 0;
        int n = A.size();
        
        s.push(0);
        for (int i = 1; i < n; i++) {
            if (A[s.top()] > A[i]) s.push(i);     
        }

        for (int i = n - 1; i >= res; i--) {
            while (A[s.top()] <= A[i]) 
            {
                res = max(res, i - s.top());
                s.pop();
                if(s.empty())return res;
            }
        }

        return res;
    }
};
```