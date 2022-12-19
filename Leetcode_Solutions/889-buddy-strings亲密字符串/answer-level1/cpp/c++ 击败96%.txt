### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
 public:

  string simplify(string s) {
    stringstream ss;
    bool added = true;
    ss << s[0];
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] != s[i - 1]) {
        ss << s[i];
      }
    }
    return ss.str();
  }

  bool buddyStrings(string A, string B) {
    if (A.size() != B.size() || A.empty() || B.empty()) return false;
    // 简化字符串 ‘accccb’ -> 'acb'
    string simpleA = simplify(A);
    string simpleB = simplify(B);
    unordered_set<char> set;
    int left = 0, right = simpleA.size() - 1, len = simpleA.size();
    // 左边第一个不同的字符
    while (left < len && simpleA[left] == simpleB[left]) {
      // 简化的字符串中可能存在重复字符  ‘abab' 和 ’abab' 是可以交换的
      set.insert(simpleA[left]);
      left++;
    }
    // 全部字符都相同, 有重复字符串就可以交换
    if (left == len) return simpleA.size() != A.size() || set.size() != simpleA.size();
    // 右边第一个不同的字符
    while (right >= 0 && simpleA[right] == simpleB[right]) {
      right--;
    }
    // 不同字符的位置一样，无法交换
    if (left == right) return false;
    // 'abac' 和 ‘abca' 是可以交换的
    return simpleA[left] == simpleB[right] && simpleA[right] == simpleB[left];
  }
};
```