### 解题思路
用一个vector容器存abc对应的数量信息，采用贪心策略，每次都取最多的那个字母，如果等于两个，就ban掉，取次多的

### 代码

```cpp
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string x = "";
        vector<int> num;
        num.push_back(a);
        num.push_back(b);
        num.push_back(c);
        while (true) {
            int ban = -1;
            if (x.length() >1 && x[x.length() - 1] == x[x.length() - 2]) {
                ban = x[x.length() - 1] - 'a';
            }
            int k = -1;
            for (int i = 0; i < 3; i++) {
                if (ban == i || num[i] == 0) {
                    continue;
                }
                if (k == -1 || num[i] > num[k]) {
                    k = i;
                }
            }
            if (k == -1) {
                break;
            }
            num[k]--;
            x += 'a' + k;
        }
        return x;
    }
};
```