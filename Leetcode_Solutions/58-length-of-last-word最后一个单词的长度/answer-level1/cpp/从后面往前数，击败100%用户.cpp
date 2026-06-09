```
class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = s.size();
        int len = 0;
        for (int i = size - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                len++;
            } else if(len > 0) {  // 排除后面空格的影响，比如"a  "
                break;;
            }
        }
        return len;
    }
};
```
![image.png](https://pic.leetcode-cn.com/b7bc661e11a6d68758338c83544dc1466835fc0cddbef5dc6786c5d26676fc05-image.png)
