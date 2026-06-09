```C++ []
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        set<int> s;
        stack<int> st;
        for (int i = 0; i < asteroids.size(); ++i) {
            int x = asteroids[i];
            if (x > 0) {
                st.push(i);
            } else {
                x *= -1;
                while (!st.empty() && asteroids[st.top()] < x) st.pop();
                if (st.empty()) s.insert(i);
                else if (asteroids[st.top()] == x) st.pop();
            }
        }
        while (!st.empty()) {
            s.insert(st.top());
            st.pop();
        }
        vector<int> res;
        for (auto i : s) {
            res.push_back(asteroids[i]);
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/f44e2845632afec00b9882b13a007b15e2e14d02279346a89c89f9fa35f21d13-image.png)
