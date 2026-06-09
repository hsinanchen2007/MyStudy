java 出入栈 个数统计 1ms
```
class Solution {
    public int balancedStringSplit(String s) {
         // 出入栈
        int count = 0;
        int res = 0;
        for (int i=0; i<s.length();i++) {
            if (s.charAt(i) == 'L') {
                count++;
            } else {
                count--;
            }

            if (count == 0) {
                res++;
            }
        }
        return res;
    }
}
```