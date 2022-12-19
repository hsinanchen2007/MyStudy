### 思路一：遍历

### 代码

```cpp
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.size(), n = p.size();
        vector<int> hash(128), res;
        for (auto c : p) {
            ++hash[c];
        }
        for (int i = 0; i <= m - n; ++i) {
            if (hash[s[i]] == 0) continue;
            if (helper(s, i, hash, n)) {
                res.push_back(i);
            }
        }
        return res;        
    }
    bool helper(string &s, int start, vector<int> hash, int cnt) {                   
       while (cnt > 0) {
           if (--hash[s[start]] < 0) return false;
           else {
               ++start;               
               --cnt;
           }
       }
       return true;
    }
};
```

### 思路二：滑动窗口（最优）


### 代码
```
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.size(), n = p.size();
        vector<int> hash(128), res;
        for (auto c : p) {
            ++hash[c];
        }
        int left = 0, right = 0, cnt = n;
        while (right < m) {
            //在哈希表中
            if (hash[s[right]] > 0) {
                --cnt;
            }
            //找到满足条件异位词
            if (cnt == 0) res.push_back(left);
            //递减哈希值并移动右指针
            --hash[s[right]];
            ++right;            
            //达到滑动窗口最大值，移动左指针前递增哈希值还原右指针减去的值
            if (right - left == n) {                
                if (hash[s[left]] >= 0) {
                    ++cnt;
                }
                ++hash[s[left]];
                ++left;
            }            
        }
        return res;        
    }
};
```
### 简化代码
```c++
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.size(), n = p.size();
        vector<int> hash(128), res;
        for (auto c : p) {
            ++hash[c];
        }
        int left = 0, right = 0, cnt = n;
        while (right < m) {
            if (hash[s[right++]]-- >= 1) --cnt;
            if (cnt == 0) res.push_back(left);
            if (right - left == n && hash[s[left++]]++ >= 0) ++cnt;
        }
        return res;        
    }
};
```
