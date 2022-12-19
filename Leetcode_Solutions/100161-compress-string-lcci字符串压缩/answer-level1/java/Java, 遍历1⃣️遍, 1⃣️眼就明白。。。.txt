🙋中午弱弱签到。。。
``` Java
class Solution {
    public String compressString(String S) {
        if (S == null || S.length() <= 2) {
            return S;
        }
        StringBuilder sb = new StringBuilder().append(S.charAt(0));
        int cnt = 1;
        for (int i = 1; i < S.length(); i++) {
            // 如果i与i-1相同，cnt累加
            if (S.charAt(i) == S.charAt(i - 1)) {
                cnt++;
            } else { 
                // 否则拼接上i-1的次数，从i开始重新计数
                sb.append(cnt).append(S.charAt(i));
                cnt = 1;
            }
        }
        return sb.append(cnt).length() < S.length()? sb.toString(): S;
    }
}
```
*另：今天的打卡题太水了没内涵。。嘘🤫*

**更新：**
遍历字符串时上面的代码改成先`char[] c = S.toCharArray()`再索引效率更高，通过`s.charAt(i)`方法索引多了方法栈和越界检查的消耗。之前本着能少写一行是一行的yuanze从来没有注意到字符串索引这点，谢谢评论区[@突围](https://leetcode-cn.com/u/tu-wei-3/)dalao指正【突然发现这题不水了233
