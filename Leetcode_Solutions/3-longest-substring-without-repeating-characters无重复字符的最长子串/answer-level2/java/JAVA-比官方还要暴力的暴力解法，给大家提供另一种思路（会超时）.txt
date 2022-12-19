 - 会超时、会超时、会超时
 - 重要的事情说三遍
 - 这里只是提供另外一种思路

```
    // 查重方法
    public static boolean allUnique(String s, int start, int end) {
        // 基于HashMap的HashSet，只存在一个键
        Set<Character> set = new HashSet<>();
        for (int i = start; i < end; i++) {
            // 返回下标为i的字符给 ch
            Character ch = s.charAt(i);
            // 判断是否有重复值
            if (set.contains(ch)) return false;
            set.add(ch);
        }
        return true;
    }

    public static int lengthOfLongestSubstring1(String s) {
        /**
         * @Method lengthOfLongestSubstring
         * @Author Sober
         * @Description 我的暴力解法（根据固定跨度改变滑动窗口位置，寻找）!!改变跨度
         * @Date 2020/3/10 21:11
         */
        // 窗口跨度
        int span = 0;
        int maxlength = 0;
        while(span < s.length()){
            // 跨度+1
            span++;
            for(int i = 0; i < s.length(); i++){
                if ((i+span) <= s.length()){
//                    这里注释的两行可以替换上面的查重方法！！！
//                    StringBuffer s2 = new StringBuffer(s.substring(i,i+span));
//                    if (span == s2.reverse().toString().replaceAll("(.)(?=.*\\1)", "").length()){
                    if (allUnique(s,i,i+span)){
                        if (maxlength < span){
                            maxlength = span;
                        }
                    }
                }
            }
        }
        return maxlength;
    }
```