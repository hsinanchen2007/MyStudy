首先看题目
1.     1
2.     11
3.     21
4.     1211
5.     111221

从题中描述可以想到基本上是归纳重复的数据进行拼接，如11表示有2个1即21，那我们首先应该想到按某一顺序将相同且没有间隔不同数字的数据进行合并，可以从左查看并归类相同，也可以从右开始，此题也可归结为查找数字中相同数字个数，相关代码如下：
```
public static String countAndSay(int n) {
        String result = "1";
        if (n == 1) {
            return result;
        }
        while (n > 1) {
            int length = result.length();
            StringBuilder param = new StringBuilder();
            int num = 1;
            for (int i = 0; i < length; i++) {
                //比较是否有相邻相同数字，有则加1
                if (i < length - 1 && result.charAt(i) == result.charAt(i + 1)) {
                    ++num;
                    continue;
                } else {
                    //相邻无相同数字后进行数据统计，并初始化统计数字
                    param.append(num).append(result.charAt(i));
                    num = 1;
                }
            }
            result = param.toString();
            n--;
        }
        return result;
    }
```
