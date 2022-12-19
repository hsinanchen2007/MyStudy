### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        vector<string> vec;
        stringstream ss(s);
        string temp;
        while (ss >> temp) {
            vec.push_back(temp);
        }
        reverse(vec.begin(), vec.end());
        string result = "";
        int n = vec.size();
        for (int i = 0; i < n; ++i) {
            result += vec[i];
            if (i != n - 1) {
                result += " ";
            }
        }
        return result;
    }
};
```