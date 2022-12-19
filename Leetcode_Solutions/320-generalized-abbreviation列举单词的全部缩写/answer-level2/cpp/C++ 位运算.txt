```
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        if (word.empty()) return {""};
        vector<string> res;
        int N = word.size();
        int S = 1 << N;
        for (int i = 0; i < S; ++i) {
            string t;
            int g = 0;
            for (int j = 0; j < N; ++j) {
                if (i >> j & 1) {
                    if (g > 0) t += to_string(g);
                    t += word[j];
                    g = 0;
                } else {
                    ++g;
                }
            }
            if (g > 0) t += to_string(g);
            res.push_back(t);
        }
        return res;
    }
};
```


![image.png](https://pic.leetcode-cn.com/91ca3a7b4aa3a192052ee4c324ef454995908a77e51e5e0f79ab3f1e65a6e329-image.png)
