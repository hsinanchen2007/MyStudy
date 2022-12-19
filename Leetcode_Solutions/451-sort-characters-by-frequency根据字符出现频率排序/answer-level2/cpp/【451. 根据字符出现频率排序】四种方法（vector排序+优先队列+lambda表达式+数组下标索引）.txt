### 思路一：利用vector自定义排序
1. 使用无序map存储字符和出现次数映射关系
2. 在vector中存储pair对，利用vector自定义排序

### 代码

```cpp
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> ump;
        for (const auto &c : s) {
            ++ump[c];
        }
        vector<pair<char, int>> vec;
        for (const auto &m : ump) {
            vec.push_back(m);
        }
        sort(vec.begin(), vec.end(), [](const pair<char, int> &p1, const pair<char, int> &p2) { return p1.second > p2.second; });
        string ret;
        for (const auto &v : vec) {
            ret += string(v.second, v.first);
        }
        return ret;
    }
};
```

### 思路二：优先队列

### 代码
```c++
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> ump;
        for (const auto &c : s) {
            ++ump[c];
        }
        priority_queue<pair<int, char>> pq;
        for (const auto &m : ump) {
            pq.push({m.second, m.first});
        }        
        string ret;
        while (!pq.empty()) {
            auto t = pq.top(); 
            pq.pop();
            ret.append(t.first, t.second);
        }
        return ret;
    }
};
```

### 思路三：利用lambda自定义排序

### 代码
```c++
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> ump;
        for (const auto &c : s) {
            ++ump[c];
        }
        sort(s.begin(), s.end(), [&](char &a, char &b) { return ump[a] > ump[b] || (ump[a] == ump[b] && a < b); });
        return s;
    }
};
```

### 思路四：数组下标索引
每个字符出现次数不会超过字符串s长度，将字符添加到字符出现次数对应数组下标处，然后从后向前遍历，如果对应下标不为空，则添加到结果集中。

### 代码
```c++
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> ump;
        for (const auto &c : s) {
            ++ump[c];
        }
        vector<string> vec(s.size() + 1);
        string res;
        for (const auto &m : ump) {
            vec[m.second].append(m.second, m.first);
        }
        for (int i = s.size(); i > 0; --i) {
            if (!vec[i].empty()) {
                res.append(vec[i]);
            }
        }
        return res;
    }
};
```


