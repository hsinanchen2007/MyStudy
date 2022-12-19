### 解题思路
![image.png](https://pic.leetcode-cn.com/e18f5f743051b723d965606ecca14e1cb7bee95d10e445c05d56c53c52246511-image.png)
- 首先从右至左遍历S，定义count_s保存当前的#号数量;
- 若count_s > i,则说明剩下的字符已无需遍历，直接break退出循环;
- 若当前字符为#，则count_s加一;
- 若当前字符不为#且count_s已有计数，则跳过这个字符，并count_s--;
- 若当前字符不为#且count_s无计数，则加上该字符;
- 对T执行同样操作
- 最后比较两个字符串是否相等即可

### 代码

```cpp
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int count_s = 0, count_t = 0;
        string s, t;
        for (int i = S.length() - 1; i >= 0; i--){
            if (count_s > i) break;
            if (S[i] == '#'){
                count_s++;
                continue;
            }
            if (S[i] != '#' && count_s > 0){
                count_s--;
                continue;
            }
            if (S[i] != '#' && count_s == 0){
                s += S[i];
            }
        }
        for (int j = T.length() - 1; j >= 0; j--){
            if (count_t > j) break;
            if (T[j] == '#'){
                count_t++;
                continue;
            }
            if (T[j] != '#' && count_t > 0){
                count_t--;
                continue;
            }
            if (T[j] != '#' && count_t == 0){
                t += T[j];
            }
        }
        cout << s << "-" << t << endl;
        return s==t;
    }
};
```