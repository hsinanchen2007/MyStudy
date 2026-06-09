方法1
```
return s.indexOf("LLL") < 0 && s.indexOf("A") == s.lastIndexOf("A");
```

方法2
```
class Solution {
    public boolean checkRecord(String s) {
        int countA = 0; // 记录A的个数
        int countL = 0; // 记录L连续出现的个数
        for (char c : s.toCharArray()) {
            if (c == 'A') {
                if (++countA == 2) {
                    return false;
                }
                countL = 0; // 当前不是L, 那么L必不连续, L计算器清零
            } else if (c == 'L') {
                if (++countL == 3) {
                    return false;
                }
            } else {
                countL = 0; // 当前不是L, 那么L必不连续, L计算器清零
            }
        }
        return true;
    }
}
```
