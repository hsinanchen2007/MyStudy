```c++
class Solution {
 public:
  int minimumLengthEncoding(vector<string>& words) {
    int ans = 0;
    string last;
    std::for_each(words.begin(), words.end(),
                  [](string& s) { std::reverse(s.begin(), s.end()); });
    std::sort(words.begin(), words.end());
    std::for_each(words.rbegin(), words.rend(), [&](const string& s) {
      ans += (last.substr(0, s.size()) != s ? s.size() + 1 : 0);
      last = s;
    });
    return ans;
  }
};
```
如果支持c++2a，可以用字符串startwith