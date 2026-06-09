思路：遍历一遍字符串，模拟将字符填入单位的过程即可。
<br/><br/>
代码：
```
class Solution {
    public int[] numberOfLines(int[] widths, String S) {
        int line = 1;// 行数
        int last = 0;// 最后一行占用的单位

        for (int i = 0;i < S.length();i++) {
            last += widths[S.charAt(i) - 'a'];
            
            if (last >= 100) {// 即将超过一行的最大宽度，更新行数和最后一行所占的单位
                line++;
                
                if (last == 100) {// 恰好为最大宽度，下一次直接在下一行写入下一个字符
                    last = 0;
                } else {// 超过最大宽度，这一行写不下了，只能写到下一行去
                    last = widths[S.charAt(i) - 'a'];
                }
            }
        }
        
        return new int[] {line,last};
    }
}
```