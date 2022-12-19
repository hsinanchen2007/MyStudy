### 解题思路
对于这种模拟类题目，搞清题意，在纸上模拟几遍就很容易写出代码了。

### 代码

```cpp
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        string s = "1", ans;
        int i, j, cnt = 1;
        for(j = 1; j < n; j++){
            //cnt = 1;
            ans = "";
            for(i = 0; i < s.length(); i++){
                if(i != s.length()-1 && s[i] == s[i+1]){
                    cnt++;
                }
                else{
                    ans += to_string(cnt) + s[i];
                    cnt = 1;
                }
            }
            s = ans;
        }
        return s;
    }
};
```