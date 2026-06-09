## 思路一：排序
排序后判断是否相等。
### 代码
```c++
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
```

## 思路二：哈希表（最优解）
### 代码
```c++
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<int, int> umap;
        for (char ch : s) {
            ++umap[ch];
        }
        for (char ch : t) {
            if (umap[ch] > 0) {
                --umap[ch];
            } else {
                return false;
            }
        }
        return true;
    }
};
```

#### 另一种写法
```c++
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> umap;
        for (int i = 0; i < s.size(); ++i) {
            ++umap[s[i]];
            --umap[t[i]];
        }
        for (auto c : umap) {
            if (c.second != 0) {
                return false;
            }
        }
        return true;
    }
};
```

#### vector模拟哈希
```c++
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        vector<int> hash(26);
        int size = s.size();
        for (int i = 0; i < size; ++i) {
            ++hash[s[i] - 'a'];
            --hash[t[i] - 'a'];
        }
        for (int n : hash) {
            if (n != 0) {
                return false;
            }
        }
        return true;
    }
};
```



