### 解题思路
根据评论区某位朋友的思路实现的代码

### 代码

```cpp
class Solution {
public:
    int countBinarySubstrings(string s) {
        int a[50010], sum = 0, pre = s[0], cur = 0, c = 0;
        a[0] = 1;
        for(int i = 1; i < s.size(); i++) {
            cur = s[i];
            if(cur == pre) {
                a[c]++;
            }
            else {
                c++;
                a[c] = 1;
            }
            pre = cur;
        }
        
        for(int i = 0; i < c; i++) {
            if(a[i+1] < a[i]) {
                sum += a[i+1];
            }
            else {
                sum += a[i];
            }
        }
        return sum;
    }
};
```