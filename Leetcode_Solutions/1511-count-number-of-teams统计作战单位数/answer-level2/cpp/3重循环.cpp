### 解题思路
使用for循环，分别限定开始数，结束数，剩下的循环遍历获取中间数

### 代码

```cpp
class Solution {
public:
    int numTeams(vector<int>& rating) {
        if (rating.size() < 3) {
            return 0;
        }

        int res = 0, sz = rating.size();
        for (int i = 0; i <= sz - 3; ++i) {
            for (int j = sz - 1; j - i >= 2; --j) {
                int start = i + 1, end = j - 1;
                while (start <= end) {
                    if (((rating[i] > rating[start]) && (rating[start] > rating[j])) || ((rating[i] < rating[start]) && (rating[start] < rating[j]))) {
                        ++res;
                    }
                    ++start;
                }
            }
        }
        return res;
    }
};
```