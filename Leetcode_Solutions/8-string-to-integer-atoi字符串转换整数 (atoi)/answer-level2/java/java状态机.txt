```java
class Solution {
    int state = 0; // 表示当前状态，初始态为0
    int sign = 1; // 符号
    int ans = 0; // 结果，符号与结果分离
    final static int INT_MAX = Integer.MAX_VALUE;
    final static int INT_MIN = Integer.MIN_VALUE;
    
    // 状态转义表
    int[][] states = {{0, 1, 2, 3},{3, 3, 2, 3},{3, 3, 2, 3},{3, 3, 3, 3}};
    
    public int myAtoi(String str) {
        int len = str.length();
        if (len <= 0) return 0;
        char[] chs = str.toCharArray();
        
        for (char c : chs) {
            state = states[state][getTrans(c)];
            if (state == 2) { // 如果经过一个c转换后变成了整数状态
                int digit = c - '0';
                if (ans > (INT_MAX - digit) / 10) { // 如果操作ans后越界，直接返回边界值
                    return sign == 1 ? INT_MAX : INT_MIN; 
                }
                ans = ans * 10 + digit;
            } else if (state == 1) {
                if (c == '+') sign = 1;
                else sign = -1;
            }
        }
        
        return sign * ans;
    }
    
    public int getTrans(char c) {
        if (c == ' ') return 0;
        if (c == '+' | c == '-') return 1;
        if (c >= '0' && c <= '9') return 2;
        else return 3;
    }
}
```
