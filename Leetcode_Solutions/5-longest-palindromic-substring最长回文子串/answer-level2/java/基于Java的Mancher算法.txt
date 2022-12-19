以下是Mancher算法的参考链接：
[https://segmentfault.com/a/1190000008484167](Mancher算法的参考链接)
```java
class Solution {
    public String longestPalindrome(String s) {
        char[] str = new char[2 * s.length() + 3];
        int[] p = new int[str.length];
        str[0] = '$'; str[1] = '#';
        for(int i = 0; i < s.length(); i++) {
            str[2 * i + 2] = s.charAt(i);
            str[2 * i + 3] = '#';
        }

        int max = 0;
        int id = 0, mx = 0;
        
        for(int i = 1; i < str.length - 1; i++) {
            if(i < mx)
                p[i] = Math.min(p[2 * id - i], mx - i);
            else
                p[i] = 1;
            
            while(str[i - p[i]] == str[i + p[i]])
                p[i]++;
            
            if(mx < i + p[i]) {
                id = i;
                mx = i + p[i];
            }
            
            max = p[max] > p[i] ? max : i;
        }
        
        StringBuilder sb = new StringBuilder();
        for(int i = max - p[max] + 1; i < max + p[max]; i++)
            if(str[i] != '#') sb.append(str[i]);
        return sb.toString();
    }
}
```
自己写的垃圾代码：
```java
class Solution {
    public String longestPalindrome(String s) {
        char[] str = new char[2 * s.length() + 3];
        int[] p = new int[str.length];
        str[0] = '$'; str[1] = '#';
        for(int i = 0; i < s.length(); i++) {
            str[2 * i + 2] = s.charAt(i);
            str[2 * i + 3] = '#';
        }

        int max = 0;
        int id = 0, md = 0;
        
        for(int i = 1; i < str.length - 1; i++) {
            while(id + p[id] <= i && id < i) id++;
            if(i < md)
                p[i] = Math.min(p[2 * id - i], md - i);
            else
                p[i] = 1;
            
            while(str[i - p[i]] == str[i + p[i]])
                p[i]++;

            max = p[max] > p[i] ? max : i;
        }
        
        StringBuilder sb = new StringBuilder();
        for(int i = max - p[max] + 1; i < max + p[max]; i++)
            if(str[i] != '#') sb.append(str[i]);
        return sb.toString();
    }
}
```
两篇的主要不同是在id的求法上
第二种写法内嵌一个while循环，增加id直到id+p[id] 能包括i为止；
第一种少了内循环，速度提升了许多
