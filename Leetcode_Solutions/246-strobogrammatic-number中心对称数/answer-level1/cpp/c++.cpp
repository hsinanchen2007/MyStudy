### 解题思路
何谓中心对称
根据题意应是,首尾两指针,如果能转换,并且转换过来的字符
首字符和末尾字符相同,末尾字符和首字符相同,则该对指针没问题,指向下一对,
否则返回false

### 代码

```cpp
class Solution {
public:
    bool isStrobogrammatic(string num) {
        if (num.empty()) {
            return false;
        }
        unordered_map<char, char> dict;
        const string f = "6", t = "9";
        for (int i = 0; i != f.size(); ++i) {
            dict[f[i]] = t[i];
            dict[t[i]] = f[i];
        }
        dict['0'] = '0', dict['8'] = '8', dict['1'] = '1';
        int first = 0, second = num.size() - 1;
        char a, b;
        while (first <= second) {
            a = dict[num[first]], b = dict[num[second]];
            if (a != num[second] || b != num[first]) {
                return false;
            }
            first += 1, second -= 1;
        }
        return true;
    }
};
```