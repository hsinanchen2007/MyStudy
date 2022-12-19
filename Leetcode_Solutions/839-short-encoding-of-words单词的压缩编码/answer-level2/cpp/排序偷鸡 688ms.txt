![Snipaste_2020-03-28_10-41-57.png](https://pic.leetcode-cn.com/02b7569fd1637b57e7bc4e6fe08502abd4d2b4c88676c3ed7574caa0bba0c84d-Snipaste_2020-03-28_10-41-57.png)
```
bool cmp(string& a, string& b) {
    return a.size() > b.size();
}
class Solution {
public:

    int minimumLengthEncoding(vector<string>& words) {
        string ret;
        cout << ret.npos << endl;
        sort(words.begin(), words.end(), cmp);
        for (auto word : words) {
            if (ret.find(word + "#") == ret.npos) {
                ret += word + "#";
            }
        }
        cout << ret << endl;
        return ret.size();

    }
};
```
