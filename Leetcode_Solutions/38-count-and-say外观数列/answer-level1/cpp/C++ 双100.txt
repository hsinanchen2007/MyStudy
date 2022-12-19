### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string countAndSay(int n) {
        map<char, int> m;
        if (n == 1) {
            return "1";
        }
        
        string res = "11";
        for (int i = 2; i < n; i++) {
            string tmp = res;
            res = "";
            int count = 1;
            int j;
            for (j = 1; j < tmp.size(); j++) {
                if (tmp[j] == tmp[j - 1]) {
                    count++;
                    continue;
                }
                res += count + '0';
                res += tmp[j - 1];
                count = 1;
            }
            res += count + '0';
            res += tmp[j - 1];
        }

        return res;    
    }
};
```