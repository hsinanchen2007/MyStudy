### 
思路来源:
https://leetcode-cn.com/problems/count-and-say/solution/c-an-shun-xu-sheng-cheng-4ms-shi-ji-xing-dai-ma-by/

```cpp
class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        
        for (int i = 1; i < n; i++) {
           string tmp;
            for (int j = 0; j < s.size(); j++) {
                int count = 1;
                while (j+1 < s.size() && s[j+1] == s[j]) { //统计重复
                    count++;
                    j++;
                }
                tmp += to_string(count) + s[j]; 
            }
            s = tmp; //更新字符串
        }
        return s;
    }
};
```