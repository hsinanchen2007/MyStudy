
虽然不是很快，但是还是记录一下

题目意思看了评论区才明白-。-

引用一下leon的评论
*题目的意思是对序列前一个数进行报数，数列第一项不是1吗，那第二项就报第一项的有1个1，输出11，然后第三项就在第二项的基础上报数，第二项是11，第三项不就是2个1么，然后输出21。。。*

```
 public static String countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        String perv = countAndSay(n - 1);
        StringBuilder sb = new StringBuilder();
        int index = 0;
        char ch = '#';
        for (int i = 0; i < perv.length(); i++) {
            if (ch != perv.charAt(i)) {
                int len = i - index;
                sb.append(len);
                sb.append(ch);
                index = i;
                ch = perv.charAt(i);
            }
        }
        int len = perv.length() - index;
        sb.append(len);
        sb.append(ch);
        System.out.println(sb.substring(2).toString());
        return sb.substring(2).toString();
    }
```

一看就知道肯定和前一个有关系了，就用递归了
终止条件就是等于1的时候，返回1。
当前任务就是拿到上一个的结果，处理后返回当前的结果。

随便拿一串数字举例 “1112123133”
肯定是先报3个1
3哪来的，肯定是3-0了，1哪来的就是刚遍历完那个

所以定义了 index 记录最开始的索引
定义 ch 记录正在遍历的字符
于是遍历整个字符串，发现与当前遍历不同的字符就记录几(len)个几(ch)，然后记住新的开始和新的字符。


缺点：
1，最开始会记录 0 个 # 所以要去掉。
2，遍历完要把最后的字符加上去

