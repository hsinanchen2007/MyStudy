### 解题思路

回溯算法，把字符串拆分成4个0-255的数字：

1. 字符串长度一定在 4-12位之间，否则不合法；
2. 分别按1-3位拆数字，大于255不合法；
3. 对于大于1位且0打头的数字，也不合法；
4. 拆分段数多于4，可以剪枝。

### 代码

```cpp
class Solution {
private:
    unordered_set<string> ips;
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.size() < 4 || s.size() > 12)
            return vector<string>();
        backtrack(s, 0, 0, "");
        vector<string> res(ips.begin(), ips.end());
        return res;
    }
    
    // i: index in s; j: index in ip
    void backtrack(string s, int i, int j, string cur) {
        if(i >= s.size()) {
            if(j == 4)
                ips.insert(cur);
            return;
        }
        if(s[i] < '0' || s[i] > '9' || j > 4)
            return;
        
        for(int k=1; k<=3; k++) {       // 有几位
            if(k > 1 && s[i] == '0')    // 处理非法0开头的数字
                break;
            int sum = 0;
            for(int p=0; p<k && i + p < s.size(); p++) {     // 第几位
                sum = sum * 10 + s[i + p] - '0';
            }
            if(sum > 255)
                break;
            string str;
            if(j < 3)
                str = cur + to_string(sum) + ".";
            else
                str = cur + to_string(sum);
            backtrack(s, i+k, j+1, str);
        }
    }
};
```

执行用时 :12 ms