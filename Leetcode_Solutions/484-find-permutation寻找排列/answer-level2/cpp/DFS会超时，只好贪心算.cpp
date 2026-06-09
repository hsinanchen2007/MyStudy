
### 代码

```cpp
class Solution {
public:
    vector<int> findPermutation(string s) {
        int n = s.size() + 1;
        vector<int> hint(n);
        int m = 1;
        hint[0] = 1;
        for (int i = 0; i < n - 1;) {
            if (s[i] == 'I') {
                int v = m;
                while (i < n - 1 && s[i] == 'I') {
                    hint[++i] = ++v;
                }
                m = v;
            } else {
                int j = i;
                int v = hint[i];
                while (j < n - 1 && s[j] == 'D') {
                    j++;
                    v++;
                }
                m = v;
                while (i <= j) {
                    hint[i++] = v--;
                }
                i--;
            }
        }
        return hint;
    }
};
auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
```