为什么我自己写的next_permutation比STL的要快。。。
STL permutation: 4ms
我的: 0ms 击败了100%
下面还给了pre_permutation的代码，区别就是有些比较反向了。
```cpp
class Solution {
private:
    bool next_permutation1(string& s) {
        if (s.size() < 2) return false;
        int cur = s.size() - 1, pre = s.size() - 2;
        while (pre >= 0 && s[pre] >= s[cur]) pre --, cur --;
        if (pre < 0) return false; // 已经逆序
        for (cur =  s.size() - 1; s[cur] <= s[pre]; cur --);
        swap(s[cur], s[pre]);
        reverse(s.begin() + pre + 1, s.end());
        return true;
    }
    bool pre_permutation(string& s) {
        if (s.size() < 2) return false;
        int cur = s.size() - 1, pre = s.size() - 2;
        while (pre >= 0 && s[pre] <= s[cur]) pre --, cur --;
        if (pre < 0) return false; // 正序
        for (cur = s.size() - 1; s[cur] >= s[pre]; cur --);
        swap(s[cur], s[pre]);
        reverse(s.begin() + pre + 1, s.end());
        return true;
    }
public:
    long long nextGreaterElement(int n) {
        string res = to_string(n);
        if (next_permutation1(res) && stoull(res) < INT_MAX) 
            return stoi(res);
        return -1;
    }
};