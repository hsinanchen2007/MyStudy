### 解题思路

参考： https://subetter.com/algorithm/rabin-karp-algorithm.html

### 代码

```cpp
class Solution {
private:
    const int mod = 1e9+7;
    const int base = 29;
    vector<long> pre;
    vector<long> product;
public:
    int distinctEchoSubstrings(string text) {
        int n = text.size();
        
        pre.resize(n + 1);
        product.resize(n + 1);
        pre[0] = 0;
        product[0] = 1;
        
        for(int i=1; i<=n; i++) {
            pre[i] = (pre[i-1] * base + text[i-1]) % mod;
        }
        
        for(int i=1; i<n; i++) {
            product[i] = product[i-1] * base % mod;
        }
        
        int count = 0;
        string_view s(text);
        unordered_set<string_view> visited[n];
        
        for(int i=1; i<=n; i++) {
            for(int j=i; j<=n; j++) {
                int len = j - i + 1;
                if(j + len <= n) {
                    if(!visited[len].count(s.substr(i-1, len)) && getHash(i, j) == getHash(j+1, j+len)) {
                        // cout << s.substr(i-1, 2 * len) << endl;
                        count++;
                        visited[len].insert(s.substr(i-1, len));
                    }
                }
            }
        }
        
        return count;
    }
    
    long getHash(int i, int j) {
        return (pre[j] - product[j - i + 1] * pre[i - 1] % mod + mod) % mod;
    }
};
```