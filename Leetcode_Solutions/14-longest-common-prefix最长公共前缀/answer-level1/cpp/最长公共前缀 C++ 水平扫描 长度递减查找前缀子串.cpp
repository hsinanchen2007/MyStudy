### 解题思路
此处撰写解题思路

### 代码

```cpp
/*
    水平扫描法O(n*m)：
    首先假设最长前缀result=strs[0], 遍历字符串数组，依次与result做比较，找出其最长前缀，然后更新result，再进行下一次比较。
    */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // 最长公共前缀res，如果str为空，res为空，否则初始化为第一个字符串
        string res = strs.size() ? strs[0] : "";
        // 遍历字符串数组
        for (auto s: strs) {
            // 循环判断出当前数组和res的公共前缀。
            while (s.substr(0, res.size()) != res) {
                res = res.substr(0, res.size() - 1);
                if (res == "") return res;
            }
        }
        return res;
    }
};


#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string res = strs.size() ? strs[0] : "";
    for (auto s: strs) {
        while (s.substr(0, res.size()) != res) {
            res = res.substr(0, res.size() - 1);
            if (res == "") return res;
        }
    }
    return res;
}

int main() {
    vector<string> strs = {"flower","flow","flight"};
    string str = longestCommonPrefix(strs);
    cout << str << endl;
}

```