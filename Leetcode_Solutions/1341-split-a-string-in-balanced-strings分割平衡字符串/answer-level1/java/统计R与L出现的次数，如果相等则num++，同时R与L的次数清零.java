### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int balancedStringSplit(String s) {
        int num = 0;
        int r = 0;
        int l = 0;
        for (char i : s.toCharArray()) {
            if (i == 'R') {
                r++;
            }
            if (i == 'L') {
                l++;
            }
            if (r == l) {
                num++;
                r = 0;
                l = 0;
            }
        }
        return num;
    }
}
```