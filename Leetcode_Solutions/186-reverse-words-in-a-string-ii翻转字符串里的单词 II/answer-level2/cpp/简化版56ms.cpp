### 代码

```cpp
class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.size(); i++) {
            int left = i;
            while (i < s.size() && s[i] != ' ') {
                i++;
            }
            reverse(s.begin() + left, s.begin() + i);
        }
    }
};
auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
```