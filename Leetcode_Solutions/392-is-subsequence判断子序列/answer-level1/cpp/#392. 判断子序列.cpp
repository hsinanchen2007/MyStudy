### 简单遍历

```cpp [1]
class Solution {
public:
    bool isSubsequence(const string &s, const string &t) {
        int i = 0, j = 0, n = s.size(), m = t.size();
        while (i < n && j < m) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i==n;
    }
};

```


### 后续挑战
由于要判断的 s 串很多，所以可以对 t 串进行预处理，生成一个哈希表，哈希表记录 26 个英文字母的下标位置，同一个英文字母对应的下标有很多，存储成有序数组。对 s 串的每个字符进行遍历，在哈希表中进行二分查找。 原问题没有注明 s 串数量特别多，所以对 t 串进行预处理收益不大。后续挑战适用于对于同一个长度很大的 t 串，判断大量 s 串是否是它的子串的情况，预先对 t 生成哈希表，之后的每一次判断子串边际成本很低。

```cpp [2]
class SolutionB {
public:
    SolutionB(const string& t)
    {
        table.resize(26);
        for (int i = 0; i < t.size(); i++) {
            table[t[i] - 'a'].push_back(i);
        }
    }
    
    bool isSubsequence(const string& s)
    {
        int pos = 0;
        for (int i = 0; i < s.size(); i++) {
            auto res = find(table[s[i] - 'a'], pos);
            if (!res.first) return false;
            pos = res.second + 1;
        }
        return true;
    }
    
private:
    // 在有序数组中查找第一个大于等于 val 的元素的下标
    pair<bool, int> find(vector<int>& v, int val)
    {
        if (v.empty()) return {false, 0};
        int low = 0, high = (int)v.size() - 1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (v[mid] >= val) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (low >= v.size()) return {false, 0};
        return {true, low};
    }
    
private:
    vector<vector<int>> table;
};
```