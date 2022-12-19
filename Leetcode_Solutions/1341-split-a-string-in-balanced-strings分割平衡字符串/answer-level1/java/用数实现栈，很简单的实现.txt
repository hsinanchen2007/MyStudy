![image.png](https://pic.leetcode-cn.com/de46373439d4f59ee2ff2138b548208a09575289c5815c173c3874007a563e41-image.png)

```
    public int balancedStringSplit(String s) {
        int stack = 0;
        int cnt = 0;
        for(char c: s.toCharArray()) {
            if(c == 'R') {
                stack--;
            } else {
                stack++;
            }
            if(stack == 0) {
                cnt++;
            }
        }
        return cnt;
    }
```
