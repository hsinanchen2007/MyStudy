```
class Solution {
    public String compressString(String S) {
        char[] chars = S.toCharArray();
        StringBuilder builder = new StringBuilder();
        int times = 1;
        for (int cur = 0, next = 1; cur < chars.length; cur++, next++) {
            // 到达终点，或者下一个字母不同，我们进行字符和出现次数的字符串拼接。
            if ( cur == chars.length - 1
                || chars[cur] != chars[next] ) {
                builder.append(chars[cur]).append(times);
                // 重置出现次数
                times = 1;
            } else {
                times++;
            }
        }
        // 根据题意输出结果
        return builder.toString().length() < S.length() ? builder.toString() : S;
    }
}
```
只有这些简答题，我才敢写题解。还是看不懂，欢迎评论中开喷我。