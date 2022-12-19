a 记录字符 'A' 的数量，l 记录字符 'L' 连续的数量，当前字符不为 'L' 则置 0 重来。
```
class Solution {
    public boolean checkRecord(String s) {
        int a = 0, l = 0;
        for (char ch : s.toCharArray()) {
            a += ch == 'A' ? 1 : 0;
            l = ch == 'L' ? l + 1 : 0;
            if (a > 1 || l > 2) {
                return false;
            }
        }
        return true;
    }
}
```
