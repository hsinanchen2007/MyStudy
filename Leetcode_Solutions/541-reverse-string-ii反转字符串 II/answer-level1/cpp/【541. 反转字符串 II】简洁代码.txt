## 思路一：遍历
### 代码
```c++
class Solution {
public:
    string reverseStr(string s, int k) {
        int size = s.size();
        int i;
        for (i = 0; i <= size - k; i += 2*k) {
            reverse(s, i, i + k - 1);
        }
        int t = size - i;        
        if (t > 0 && t < k) {
            reverse(s, i, size - 1);  
        }
        return s;
    }
    void reverse(string &s, int left, int right) {
        while (left < right) {
            swap(s[left], s[right]);
            ++left, --right;
        }
    }
};
```
### 简化代码
```c++
class Solution {
public:
    string reverseStr(string s, int k) {
        int size = s.size();        
        for (int i = 0; i < size; i += 2*k) {
            reverse(s.begin() + i, min(s.begin() + i + k, s.end()));
        }
        return s;
    }
};
```

