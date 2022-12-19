自己写完之后想看一下题解里面更好的C#解法，发现竟然还没人上传C#解法，斗胆发一次题解

思路：
1、先将string类型转换成char[]类型方便操作
2、将words里面的单词一一取出来进行转换
3、定义两个标记数a，b来记录排序后的chars和word
4、判断是否相同
5、最后将长度赋值给re返回值

```
    public int CountCharacters(string[] words, string chars) {
        var ch = chars.ToCharArray();
        Array.Sort(ch);
        int re = 0;
        foreach (var word in words) {
            int a = 0, b = 0;
            var wo = word.ToCharArray();
            Array.Sort(wo);
            while (a < wo.Length && b < ch.Length) {
                if (wo[a] == ch[b]) {
                    a++;
                    b++;
                    if (a == wo.Length) {
                        re += word.Length;
                    }
                } else {
                    b++;
                    if (b == chars.Length || ch[b] > wo[a]) {
                        break;
                    }
                }
            }

        }
        return re;
    }
```
