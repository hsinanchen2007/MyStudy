### 解题思路
模拟
又一次双百
![捕获.JPG](https://pic.leetcode-cn.com/b84beebfd7f7319bb3d24aedca10a8355874b8add59e2dcaf27222d4fae475cc-%E6%8D%95%E8%8E%B7.JPG)

### 代码

```cpp
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> vec1;
        vector<int> vec2;
        int left = 0;
        for (int i = 0; i < version1.size(); i++) {
            if (version1[i] == '.') {
                vec1.push_back(atoi((version1.substr(left, i - left)).c_str()));
                i++;
                left = i;
            }
        }
        if (left < version1.size()) {
            vec1.push_back(atoi((version1.substr(left, version1.size() - left)).c_str()));
        }
        left = 0;
        for (int i = 0; i < version2.size(); i++) {
            if (version2[i] == '.') {
                vec2.push_back(atoi((version2.substr(left, i - left)).c_str()));
                i++;
                left = i;
            }
        }
        if (left < version2.size()) {
            vec2.push_back(atoi((version2.substr(left, version2.size() - left)).c_str()));
        }
        int n1 = vec1.size();
        int n2 = vec2.size();
        if (n1 < n2) {for (int i = n1; i < n2; i++) {vec1.push_back(0);}}
        if (n1 > n2) {for (int i = n2; i < n1; i++) {vec2.push_back(0);}}
        for (int i = 0; i < vec1.size(); i++) {
            if (vec1[i] > vec2[i]) {
                return 1;
            } else if (vec1[i] < vec2[i]) {
                return -1;
            }
        }
        return 0;
    }
};
```