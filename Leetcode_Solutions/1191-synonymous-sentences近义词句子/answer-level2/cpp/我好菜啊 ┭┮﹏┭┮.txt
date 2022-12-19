并查集+DFS+sort，我好菜啊 ┭┮﹏┭┮

```c++
class Solution {
 public:
  vector<string> ans;
  map<string, string>f;

  vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
    createUnionFind(synonyms);
    vector<string> vecT = split(text, " ");
    ans.clear();
    DFS(vecT, 0, f);
    sort(ans.begin(), ans.end());
    return ans;
  }

  void DFS(vector<string>text, int d, map<string, string>us) {
    if(d == text.size()) {
      ans.push_back(toStr(text));
      return;
    }
    if(us.find(text[d]) == us.end()) {
      DFS(text, d + 1, us);
    } else {
      string setId = getF(text[d]);
      for(auto p : us) {
        if(getF(p.first) == setId) {
          text[d] = p.first;
          DFS(text, d + 1, us);
        }
      }
    }
  }

  string toStr(vector<string> v) {
    string ans;
    for(int i = 0, sz = v.size(); i < sz; ++i)
      ans += v[i] + (i == sz - 1 ? "" : " ");
    return ans;
  }

  void createUnionFind(vector<vector<string>> synonyms) {
    for(auto syn : synonyms)
      for(auto s : syn)
        f[s] = s;
    for(auto syn : synonyms) {
      string c = syn[0];
      for(string s : syn)
        unionSet(c, s);
    }
  }

  string getF(string x) {
    return f[x] = (f[x] == x ? x : getF(f[x]));
  }

  void unionSet(string x, string y) {
    x = getF(x), y = getF(y);
    if(x == y)
      return;
    f[x] = y;
  }
  vector<string> split(string s, string delim) {
    vector<string> ans;
    string::size_type pos_1, pos_2 = 0;
    while(pos_2 != s.npos) {
      pos_1 = s.find_first_not_of(delim, pos_2);
      if(pos_1 == s.npos)
        break;
      pos_2 = s.find_first_of(delim, pos_1);
      ans.push_back(s.substr(pos_1, pos_2 - pos_1));
    }
    return ans;
  }
};

```
