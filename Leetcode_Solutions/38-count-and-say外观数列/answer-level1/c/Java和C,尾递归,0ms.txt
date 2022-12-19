- 执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
- 内存消耗 :7.1 MB, 在所有 C 提交中击败了71.76%的用户

思想:只要读懂题意,这道题很简单。即下一个数说出了上一个数的组成,所以,按照这个思路就把上一个数依次从左往右读就行,比如:上一个数是11,那上一个数就由2个1组成,所以下一个数是21;再例如:上一个数是111221,就由3个1、2个2、1个1组成,那下一个数就是312211。代码有详细注释:
```C []
/* 尾递归 */
char *countHelper(char *s, int n)
{
    if (n == 1)
        return s;
    else
    {
        //求下一个数
        int count;
        char ch[10000];
        char *p = ch;
        //一直读数
        while (*s!='\0')
        {
            count = 1;
            //如果一直是同一个数
            while (*s==*(s+1))
            {
                count++;
                s++;
            }
            //下一个数更新
            *p++ = (char)(count+'0');
            *p++ = *s++;
        }
        return countHelper(ch, n - 1);
    }
}

char *countAndSay(int n)
{
    return countHelper("1", n);
}
```
```Java []
public class CountAndSay {

    public static String countAndSay(int n) {
        return countHelper("1", n);
    }

    /**
     * 尾递归
     * @param str
     * @param n
     * @return
     */
    private static String countHelper(String str, int n) {
        if (n == 1) return str;
        else {
            //求下一个数
            StringBuilder stringBuilder = new StringBuilder();
            int i = 0;
            //一直读数
            while (i < str.length()) {
                int count = 1;
                //如果一直是同一个数
                while (i < str.length() - 1 && str.charAt(i) == str.charAt(i + 1)) {
                    count++;
                    i++;
                }
                //下一个数更新
                stringBuilder.append(Integer.toString(count) + str.charAt(i));
                i++;
            }
            str = stringBuilder.toString();
        }
        return countHelper(str, n - 1);
    }
    
}
```

