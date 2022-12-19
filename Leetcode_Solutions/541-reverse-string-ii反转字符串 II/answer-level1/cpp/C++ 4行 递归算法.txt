![捕获.PNG](https://pic.leetcode-cn.com/5a51af5ed0baa3488ced087ad29e4a24b39f144c211ab24049f946a2fb8ac5e5-%E6%8D%95%E8%8E%B7.PNG)

```cpp
string reverseStr(string s, int k) {
    if (s.length() <= k) {reverse(s.begin(), s.end()); return s;}
    reverse(s.begin(), s.begin() + k);
    if (s.length() <= k << 1) return s;
    return s.substr(0, k << 1) + reverseStr(s.substr(k << 1), k);
}
```