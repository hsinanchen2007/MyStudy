![image.png](https://pic.leetcode-cn.com/a77b81d0dd8d479dbf738de1b081d1362821aab9720820024d55e9bd17fffebe-image.png)


```
class Solution {
public:
    int magicalString(int n) {
        string s = "1221121";
        int countOnes = 0;
        int countChars = 0;
        bool isOne = true;
        for (int i = 0; i < n; ++i) {
            if (isOne) {
                countOnes += s[i] - '0';
            }
            countChars += s[i] - '0';
            if (countChars >= n) {
                break;
            }
            if (countChars > s.size()) {
                s.insert(s.size(), s[i] - '0', isOne ? '1' : '2');
            }
            isOne = !isOne;
        }
        if (isOne && countChars > n) return countOnes-1;
        return countOnes;
    }
};
```
