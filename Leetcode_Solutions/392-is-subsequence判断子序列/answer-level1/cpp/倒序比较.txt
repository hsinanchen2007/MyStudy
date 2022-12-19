![QQ图片20200209165142.png](https://pic.leetcode-cn.com/04222b796b484718a998f4a6a58a61b9f82c8b18de4d7e89a22a6128430951ab-QQ%E5%9B%BE%E7%89%8720200209165142.png)

```
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int len1 = s.length();
        long long len2 = t.length();
        long long ma = len2;
        for(int i = len1 - 1; i >= 0; i--){
            bool f = false;
            for(int j = ma - 1; j >= 0; j--){
                if(s[i] == t[j]){
                    ma = j;
                    f = true;
                    break;
                }  
            }
            if(f == false){
                return false;
            }
        }
        return true;
    }
};
```
