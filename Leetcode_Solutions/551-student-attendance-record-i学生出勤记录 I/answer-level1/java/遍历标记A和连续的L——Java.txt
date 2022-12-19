思路：遍历字符串，标记A和连续的L数目，最后判断条件即可。
<br/><br/>
代码：
```
class Solution {
    public boolean checkRecord(String s) {
        int a = 0;
        int l = 0;
        
        for (int i = 0;i < s.length();i++) {
            if (s.charAt(i) == 'A') {
                a++;
            }
            
            int c = 0;
            while (i < s.length() && s.charAt(i) == 'L') {
                c++;
                i++;
            }
            
            l = Math.max(l,c);
            
            if (c > 0) {
                i--;// 这里i需要--，因为统计退出条件会让i指向L的下一个字符，然后外面的for循环i++，这时候就会跳过L的下一个字符，会有遗漏
                // 或者i不--，像下面那样再检查一次也可以
                // if (i < s.length() && s.charAt(i) == 'A') {
                //     a++;
                // }
            }
        }
        
        return a <= 1 && l <= 2;
    }
}
```