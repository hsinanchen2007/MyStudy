![image.png](https://pic.leetcode-cn.com/9218750842e8be094cf3218772f3159a7273e51c12f891b504218b7fab6a130d-image.png)

```
class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        size_t pos = 0;
        vector<string> results;
        while ((pos = s.find("++", pos)) != string::npos) {
            string temp = s;
            results.emplace_back(move(temp.replace(pos++, 2, "--")));
        }
        return results;
    }
};
```

