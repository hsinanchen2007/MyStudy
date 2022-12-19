### 解题思路

### 代码

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if (A.size() == 0) {
            return 0;
        }
        map<int, int> m;
        deque<int> dq;
        for (auto a : A) {
            m[a]++;
        }
        for (auto p : m) {
            dq.push_back(p.first);
        }
        // dq.push_back(40001);
        dq.push_back(INT_MAX);
        int len = dq.size();
        int sum = 0;
        int k = 0;
        int nxt = 0;
        for (int i = 0; i < len - 1; i++) { // 0 2
            int a = dq[i];
            int cnt = m[a];
            if (k <= a) {
                k = dq[i] + 1;
                nxt = i + 1;
            }
            while (cnt > 1) {
                if (k < dq[nxt]) {
                    sum += (k - a);
                    k++;
                    cnt--;
                } else {
                    k = dq[nxt] + 1;
                    nxt++;
                }
            }
        }
        return sum;
    }
};
```