### 解题思路
设置个计数器 若cnt为0 说明是新数字 创建数字 因为是跟后一个字符相比，所以此时不要++i
最后一个字符虽然比较了 但是缺少对最后字符的处理 需要单独处理

### 代码

```cpp
class Solution {
public:
    string compressString(string S) {
        string tmp;
        if (S.empty()) return tmp;
        int cnt = 0;
        for (int i = 0; i < S.size() - 1; ) {
            if (cnt == 0) {
                tmp += S[i];
                cnt++;
            } else {
                if (S[i] == S[i + 1]) {
                    cnt++;
                    ++i;
                } else {
                    tmp += to_string(cnt);
                    cnt = 0;
                    ++i;
                }
            }
        }
        //直接判断cnt即可 若cnt不为0说明 最后一个是重复的 否则直接加 s[i] + 1即可
        if (cnt) {
            tmp += to_string(cnt);
        } else {
            tmp = tmp + S[S.size() - 1] + "1";
        }
        return tmp.size() < S.size() ? tmp : S;
    }
};
```