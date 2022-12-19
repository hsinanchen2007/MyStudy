### 解题思路
回溯法，详见注释

### 代码

```cpp
class Solution {
public:
    // 用来代替map<char, int>，charmap比map会快5倍左右
    class charmap {
      public:
        int nums[26] = {0};
        int& operator[](char c) {
          return nums[c - 'a'];
        }
        int& data(int i) {
          return nums[i];
        }
    };

    // 用于sort stickers转换的charmap。不排序不影响结果，排序会快12ms
    class myclass {
      public:
      bool operator() (charmap &m1, charmap& m2) {
        int sum1 = 0;
        int sum2 = 0;
        for (int i = 0; i < 26; ++i) {
          sum1 += m1.data(i);
          sum2 += m2.data(i);
        }

        return sum1 > sum2;
      }
    };

    // 回溯法，相当于dfs
    void inner(vector<charmap>& data, charmap& tmap, int& sum, int& min_sum) {
      // tmap里面存储的为剩余的每个字符个数，如果任何一个字符大于0，说明还需要继续搜索
      char find_c;
      bool finished = true;
      for (int i = 0; i < 26; ++i) {
        if (tmap.data(i) > 0) {
          find_c = i + 'a';
          finished = false;
          break;
        }
      }
      // 如果全部都小于0，则说明搜索到一个解
      if (finished) {
        if(min_sum == 0) {
          min_sum = sum;
        } else {
          min_sum = min(min_sum, sum);
        }
        return;
      }

      for (int i = 0; i < data.size(); ++i) {
        // 如果data[i]中不包含要找的find_c，则跳过
        if (data[i][find_c] > 0) {
          // 如果当前sum + 1已经大于全局最小解，则没必要继续搜索
          if (min_sum != 0 && sum + 1 >= min_sum) {
            continue;
          }
          // 对于包含find_c的data[i]，还可能有其他字符也在target中，需要减去这个值
          for (int j = 0; j < 26; ++j) {
            if (data[i].data(j) > 0) {
              tmap.data(j) -= data[i].data(j);
            }
          }
          // 单词个数增加
          sum += 1;
          inner(data, tmap, sum, min_sum);
          // 下面两步是回溯
          sum -= 1;
          for (int j = 0; j < 26; ++j) {
            if (data[i].data(j) > 0) {
              tmap.data(j) += data[i].data(j);
            }
          }
        }
      }
    }

    int minStickers(vector<string>& stickers, string target) {
      charmap tmap;
      // 转换target为charmap
      for (char& c : target) {
        ++tmap[c];
      }

      set<char> all;
      vector<charmap> data;
      for (auto& val : stickers) {
        bool usefull = false;
        charmap tmp;
        for (char& c : val) {
          if (tmap[c] > 0) {
            usefull = true;
          }
          ++tmp[c];
          all.insert(c);
        }
        // 对于不包含target任何字符的sticker，没必要搜索
        if (usefull) {
          data.push_back(tmp);
        }
      }

      // 如果有任何target中的字符没有出现在stickers中，返回-1
      for (char& c : target) {
        if (all.find(c) == all.end()) {
          return -1;
        }
      }

      int min_sum = 0;
      int sum = 0;
      sort(data.begin(), data.end(), myclass());
      inner(data, tmap, sum, min_sum);
      return min_sum;
    }
};
```