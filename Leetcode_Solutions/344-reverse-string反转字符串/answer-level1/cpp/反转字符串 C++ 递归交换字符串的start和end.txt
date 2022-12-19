### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.empty()) return;
        recursive(s, 0, s.size()-1);
    }

    void recursive(vector<char> &s, int start, int end) {
        if (start > end) return;
        // 递归
        recursive(s, start+1, end-1);
        // 交换
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
    }
};

#include <iostream>
#include <vector>

using namespace std;

void recursive(vector<char>& s, int start, int end) {
    if (start > end) return;
    recursive(s, start+1, end-1);
    char temp = s[start];
    s[start] = s[end];
    s[end] = temp;
}

void reverseString(vector<char>& s) {
    if (s.empty()) return;
    recursive(s, 0, s.size()-1);
}

int main() {
    vector<char> v = {'a', 'b', 'c', 'd'};
    reverseString(v);
    for (int i=0; i<v.size(); i++) {
        cout << v[i];
    }
}






```