### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> fraction(vector<int>& cont) {
        if (cont.empty()) {
            return cont;
        }
        long int first = 1, second = cont[cont.size() - 1];
        for (int i = cont.size() - 2; i > 0; --i) {
            Convert(cont[i], first, second);
        }
        if (cont.size() == 1) {
            second  = 1;
            first = 0;
        }
        Convert(cont[0], first, second);
        UnionOne(first, second);
        vector<int> res;
        res.push_back(second);
        res.push_back(first);
        return res;
    }
    void Convert(int a, long int& first, long int& second) {
        first += a * second;
        swap(first, second);
    }
    void UnionOne(long int& first, long int& second) {
        int f = first, s = second, count = 0, t;
        if (first == second || first == 1 || second == 1) {
            return ;
        }
        while (true) {
            if (f % 2 == 0 && s % 2 == 0) {
                count += 1;
                f /= 2, s /= 2;
            } else {
                t = abs(f - s);
                if (t == min(f, s)) {
                    break;
                }
                f = max(t, s);
                s = min(t, s);
            }
        }
        for (int i = 0;i < count; ++i) {
            t *= 2;
        }
        first /= t, second /= t;
    }
};
```