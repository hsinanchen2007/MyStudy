### 解题思路
回溯法
用int的26个bit表示字符是否存在出现过
详见注释
### 代码

```cpp
class Solution {
public:
    // 判断两个字符串是否有交集，即是否它们为可行解的一部分
    bool valid(int& s1, int& s2) {
      return s1 + s2 == (s1 | s2);
    }

    // 获取一个数中包含的1的个数，即unique string的size
    int bit_num(int& num) {
      int res = 0;
      for (int i = 0; i < 32; ++i) {
        int cbit = 1 << i;
        if ((num & cbit) == cbit) {
          ++res;
        }
      }
      return res;
    }

    // data表示所有候选string集合，已去重
    // last表示当前最长候选解的字符集合；
    // level表示遍历深度
    // len 表示当前最长候选解的长度
    //  ans表示最大长度
    void backtrack(vector<int>& datas, int& last, int level, int& len, int& ans) {
      ans = max(len, ans);

      int prev = -1;
      for (int i = level; i < datas.size(); ++i) {
        // 先确定当前str和last是否可以合并为可行解
        // 第二个条件的意思是：level层的第一个string必选，后面遍历的data[i]如果和它没有交集，那么就不需要重新遍历了
        // 因为同一层遍历时，以datas[level]为root的tree，一定有一个path包含和它互斥的所有string。只有和它有交集的那些string才可能产生不同解
        if (valid(last, datas[i]) && (prev == -1 || !valid(datas[i], datas[prev]))) {
          prev = i;
          // 类似全排列的回溯
          swap(datas[level], datas[i]);
          len += bit_num(datas[level]);
          last += datas[level];
          backtrack(datas, last, level + 1, len, ans);
          last -= datas[level];
          len -= bit_num(datas[level]);
          swap(datas[level], datas[i]);
        }
      }
    }

    int maxLength(vector<string>& arr) {
      set<int> s;
      vector<int> datas;

      for (auto& str : arr) {
        int data = 0;
        // 如果str中的char个数大于2，则此string为非候选解
        bool dup = false;
        for (auto& c : str) {
          int cbit = 1 << c - 'a';
          if ((data & cbit) == cbit) {
            dup = true;
            break;
          } else {
            data |= cbit; 
          }
        }

        // 过滤全局相同的string，["ab", "ab", "ba"] => ["ab"]
        if (dup || s.find(data) != s.end()) {
          continue;
        }
        s.insert(data);
        datas.push_back(data);
      }

      int last = 0;
      int len= 0;
      int ans = 0;
      backtrack(datas, last, 0, len, ans);

      return ans;
    }
};
```