并没有想到原地枚举子集，写一个蠢蠢的二进制枚举，复杂度主要在STL上了QAQ
```c++
class Solution {
public:
  vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
    int n = words.size(), m = puzzles.size();
    vector<int> ret(m, 0);
    unordered_map<int, int> w;
    for (int i = 0; i < n; i++) {
      int tmp = 0;
      for (int j = 0; j < words[i].length(); j++) {
        tmp |= 1 << (words[i][j] - 'a');
      }
      w[tmp]++;
    }
    unordered_set<int> help;
    vector<int> sub;
    for (int i = 0; i < m; i++) {
      int p = 0;
      help.clear();
      for (int j = 0; j < puzzles[i].length(); j++) {
        p |= 1 << (puzzles[i][j] - 'a');
        help.insert(1 << (puzzles[i][j] - 'a'));
      }
      sub.assign(help.begin(), help.end());
      for (int j = 1; j < (1 << sub.size()); j++) {
        int tmp = 0;
        for (int k = 0; k < sub.size(); k++) {
          if ((1 << k) & j) tmp |= sub[k];
        }
        if (1 << (puzzles[i][0] - 'a') & tmp) ret[i] += w[tmp];
      }
    }
    return ret;
  }
};
```