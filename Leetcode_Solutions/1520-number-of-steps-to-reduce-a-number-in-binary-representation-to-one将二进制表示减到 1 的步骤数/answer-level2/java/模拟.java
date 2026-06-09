将字符串转换为字符数组进行模拟。最高为有进位时，需要在返回初判断结果+1。

```
class Solution {
    public int numSteps(String s) {
        if (s.length() == 1) return 0;

        char[] chars = s.toCharArray();
        int last = chars.length - 1;
        int ans = 0;
        while (last > 0) {
            ans++;
            if (chars[last] == '1') {
                chars[last] = '0';
                int i = last - 1;
                while (i >= 0 && chars[i] != '0') {
                    chars[i] = '0';
                    i--;
                }
                if (i >= 0) {
                    chars[i] = '1';
                }
            } else {
                last--;
            }
        }
        return chars[last] == '0' ? ans + 1 : ans;
    }
}
```
