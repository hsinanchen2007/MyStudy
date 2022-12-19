### 解题思路
Split切开后，采用Stoll分析，并逐个比较

### 代码

```cpp
class Solution {
public:
    int compareVersion(string version1, string version2) {
//        if (version1.empty() && version2.empty()) {
//            return 0;
//        } else if (version1.empty() && !version2.empty()) {
//            return -1;
//        } else if (version2.empty() && !version1.empty()) {
//            return 1;
//        }
        vector<long long> v1 = Div(version1);
        vector<long long> v2 = Div(version2);
        if (v1.size() > v2.size()) {
            int div = static_cast<int>(v1.size() - v2.size());
            for (int i = 1; i <= div; i++) {
                v2.push_back(0);
            }
        } else {
            int div = static_cast<int>(v2.size() - v1.size());
            for (int i = 1; i <= div; i++) {
                v1.push_back(0);
            }
        }

        for (int i = 0; i < v1.size(); i++) {
            if (v1[i] == v2[i]) {
                continue;
            } else if (v1[i] > v2[i]) {
                return 1;
            } else {
                return -1;
            }
        }
        return 0;
    }

    vector<long long> Div(string version) {
        vector<long long> vec;
        int index = 0;
        version = version+ '.';
        for (int i = 0 ; i < version.size(); i++) {
            if (version[i] == '.') {
                vec.push_back(stoll(version.substr(index, i - index)));
                index = i + 1;
            }
        }
        return vec;
    }
};
```