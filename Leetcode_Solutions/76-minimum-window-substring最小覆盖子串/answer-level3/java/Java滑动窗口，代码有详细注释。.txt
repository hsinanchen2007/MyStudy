### 解题思路
通过数组来替换原来的HashMap，提高性能。执行用时 : 5 ms

### 代码

```java
class Solution {
    public String minWindow(String s, String t) {
        //由于字符类型，就考虑所有的ASCII码，因此直接用128个长度的数组代替原来的HashMap,提高性能
        //用来统计t中每个字符出现次数
        int[] needs = new int[128];
        //用来统计滑动窗口中每个字符出现次数
        int[] window = new int[128];
        //统计t中每个字符出现次数
        for (char ch : t.toCharArray()) {
            needs[ch] = needs[ch]+1;
        }
        int l = 0, r = 0;
        int plength = t.length();
        //候选字符数
        int count = 0;
        int minLength = s.length()+1;
        String result = "";
        while (r < s.length()) {
            char ch = s.charAt(r);
            //统计滑动窗口中每个字符出现次数
            window[ch] = window[ch]+1;
            // 当这个字符是在t中，并且t需要的次数大于等于该字符在滑动窗口出现的次数，被确定为候选字符。
            if (needs[ch] > 0 && needs[ch]  >= window[ch]) {
                count++;
            }
            //当候选字符数等于t的长度时，说明滑动窗口中的字符串包含T，开始移动l，缩小窗口
            //直到不满足count == plength时，继续扩展窗口
            while (count == plength){
                ch = s.charAt(l);
                if (needs[ch] > 0 && needs[ch]  >= window[ch]){
                    count--;
                }
                //找出长度最短符合条件的结果 (r-l)+1计算当前窗口大小
                if ((r-l)+1 < minLength){
                    minLength = (r-l)+1;
                    result = s.substring(l,r+1);
                }
                window[ch] = window[ch]-1;
                l++;
            }
            r++;
        }
        return result;
    }
}
```