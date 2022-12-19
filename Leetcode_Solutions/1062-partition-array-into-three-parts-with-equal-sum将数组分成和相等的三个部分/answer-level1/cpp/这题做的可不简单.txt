### 解题思路
此处撰写解题思路
对比了一下其他玩家的简单的双指针，自己用了复杂的贪心算法。折腾了好久，还搞出来。不过好处是若是题目改为4组，五组，六组，我也就改个参数的事情。
### 代码

```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int> const &A) {
        int s = 0;
        for (auto c : A) {
            s += c;
        }
        cout << s << endl;
        if (s % 3) {
            return false;
        }
        s /= 3;
        int tmp = 0;
        auto itr = A.begin();
        stack<pair<vector<int>::const_iterator, int>> ss;
        ss.emplace(A.begin(), 0);

        while (!ss.empty() || itr != A.end()) {
            if (itr == A.end()) {
                auto ret = ss.top();
                tmp = ret.second;
                itr = ret.first;
                ss.pop();
            }
            tmp += *itr++;
            if (tmp == s) {
                if (itr == A.end()) {
                    if (ss.size() == 3) {
                        return true;
                    } else {
                        continue;
                    }
                }
                ss.emplace(itr, s);
                tmp = 0;
            }
        }
        return false;
    }
};

```