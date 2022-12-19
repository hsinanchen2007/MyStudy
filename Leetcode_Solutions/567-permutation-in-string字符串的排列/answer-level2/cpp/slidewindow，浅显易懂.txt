### 解题思路
slideWindow保存当前窗口内的字母组合

### 代码

```cpp
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        unordered_multiset<char> targetStr;
        for (auto each : s1) {
            targetStr.insert(each);
        }

        unordered_multiset<char> slideWindow(s2.begin(), s2.begin() + s1.size());

        for (int front = s1.size(); front <= s2.size(); ++front) {
            if (slideWindow == targetStr) {
                return true;
            }

            slideWindow.insert(s2[front]);

            auto it = slideWindow.find(s2[front - s1.size()]);
            slideWindow.erase(it);
        }

        return false;
    }
};

```