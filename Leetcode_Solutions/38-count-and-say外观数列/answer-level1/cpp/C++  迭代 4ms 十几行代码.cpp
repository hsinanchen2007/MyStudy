从1开始生成直到n这样一步一步来写，感觉这样比较好理解
```
class Solution {
public:
    string countAndSay(int n) {
        std::string s = "1";
        
        for (int i = 1; i < n; i++) {
            std::string tmp;
            for (int j = 0; j < s.size(); j++) {
                int count = 1;
                while (j+1 < s.size() && s[j+1] == s[j]) { //统计重复
                    count++;
                    j++;
                }
                tmp += std::to_string(count) + s[j]; 
            }
            s = tmp; //更新字符串
        }
        return s;
    }
};
```

