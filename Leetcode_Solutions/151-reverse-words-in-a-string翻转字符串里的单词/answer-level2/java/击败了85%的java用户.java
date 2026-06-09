## [更多leetcode分类题解](https://github.com/reedfan/leetcode/tree/master/src/main/java/leetcode)
```
public String reverseWords(String s) {
        if (s == null || s.length() < 1) {
            return "";
        }
        StringBuffer res = new StringBuffer();
        //用来标记是不是第一个单词，是第一个单词，前面就不加" "；
        boolean first = true;
        //统计这个单词有几个字符
        int cnt = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) != ' ') {
                cnt++;
                continue;
            }
            if (cnt != 0) {

                if (first) {
                    first = false;
                } else {
                    res.append(" ");
                }
                res.append(s.substring(i + 1, i + 1 + cnt));
                cnt = 0;
            }

        }
        if (cnt != 0) {
            if(!first){
                res.append(" ");
            }

            res.append(s.substring(0, cnt));
        }

        return res.toString();

    }
```
