## 解答
时间复杂度: *O(N)*
空间复杂度：*O(1)*
```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        const int t_size = t.size();
        const int s_size = s.size();
        int flag = 0;
        for (int i = 0; i < s_size; i++) { // 依次遍历s中的每一个字符
            const auto sc = s[i];
            while (flag < t_size && sc != t[flag]) // 从上次搜到的地方之后继续搜索当前要搜的字符
                flag++;
            if (flag < t_size) {
                flag++;
            } else { // 当前字符未搜到
                return false;
            }
        }
        return true;
    }
};
```

## 进阶
t固定，批量进行s查找
每次查找的时间复杂度：*O(Log(N))*
全局空间复杂度：*O(1)*
```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        set<int> alpha_set[26];
        const int t_size = t.size();
        // 为每个字符串用set存储所有对应字符出现的位置
        for (int i = 0; i < t_size; i++) {
            alpha_set[t[i] - 'a'].insert(i);
        }
        int last = -1;
        for (const auto c : s) {
            const auto &cset = alpha_set[c - 'a'];
            // set内部使用的是平衡二叉树实现的，插入时已经排序
            // 这里的查找时间开销是O(Log(N))
            auto it = cset.upper_bound(last);
            if (it == cset.end())
                return false;
            last = *it;
        }
        return true;
    }
};
```