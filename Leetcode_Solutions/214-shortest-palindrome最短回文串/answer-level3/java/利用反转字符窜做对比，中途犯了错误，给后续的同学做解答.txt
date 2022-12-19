1、首先反转字符串得到revs；
2、然后利用其中一个字符串的字串判断是否为另一个字符串的开头；
    a、以原字符串为基准，截取反转字符串；
    b、以反转字符串为基准，截取原字符串；
3、只要有其中一个找到符合条件的结果，就可以以此组装最短回文；


以此逻辑虽说正确但是在执行过程中碰到两个问题，以下代码中注释部分有1、2两个代码块

如果1放在2上面，提交测试用例时会碰到：
输入:
"abb"
输出
"abba"
预期结果
"bbabb"

如果2放在1上面，提交测试用力时会碰到：
输入：
"abcd"
输出：
"abcdcba"
预期：
"dcbabcd"

当看到这里的时候，跟我范同样错误的同学，一定要仔细阅读题目，题目是要求在“前面”添加字符串，这时删除2的代码块即可通过

```
    public String shortestPalindrome(String s) {
        String revs = new StringBuilder(s).reverse().toString();
        String res = s;
        for(int i =0;i<s.length();i++){
            //标注的这两段判断，互换位置的话，执行的结果可能会不一样
            //1
            String temp = revs.substring(i);
            if(s.startsWith(temp)){
                res = revs.substring(0,i)+s;
                break;
            }
            //1

            //2，如果要直行通过，需要把这块代码删除，保留此代码可以查找前后添加字符串最短回文
            temp = s.substring(i);
            if(revs.startsWith(temp)){
                res = s+revs.substring(s.length()-i);
                break;
            }
            //2
        }
        return res;
    }
```


