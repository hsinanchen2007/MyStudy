一次遍历,当遍历到的字符不是空格时,temp加1,当遍历到最后一个字符不是空格时,结果加1;
当遍历到的字符是空格并且temp大于0的时候结果加1。
代码如下:
```
public int countSegments(String s) {

        if (s == null || s.length() == 0) {
            return 0;
        }

        int res = 0;
        int temp = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c != ' ') {
                temp++;
                if (i == s.length() - 1) {
                    res++;
                }
            } else if (c == ' ' && temp > 0) {
                res++;
                temp = 0;
            }
        }

        return res;

    }
```
