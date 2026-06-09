### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void reverseString2(vector<char>& s) { // 非递归算法 ...
        int i = -1, j = s.size();
        while (++i < --j) {
            swap(s[i], s[j]);
        }
    }

    void reverseString(vector<char>& s) { // 递归算法 ...
        reverseString(s, 0, s.size() - 1);
    }

    void reverseString(vector<char>& s, int l, int r) {

        if (l >= r) return;

        swap(s[l], s[r]);
        reverseString(s, l + 1, r - 1);
    }
};
```