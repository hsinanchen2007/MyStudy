>欢迎大家关注我的LeetCode代码仓：[https://github.com/617076674/LeetCode]()
>几乎所有题目都会提供多种解法，真诚求star！

# 记录每个字符出现的次数，一旦该出现的次数用完，取下一个新字符

执行用时：17ms，击败47.06%。消耗内存：41.5MB，击败5.55%。

```java
public class StringIterator {
    private String s;

    private int index, num;

    private char c;

    public StringIterator(String s) {
        this.s = s;
    }

    public char next() {
        if (!hasNext()) {
            return ' ';
        }
        if (num == 0) {
            c = s.charAt(index++);
            while (index < s.length() && s.charAt(index) >= '0' && s.charAt(index) <= '9') {
                num = num * 10 + s.charAt(index++) - '0';
            }
        }
        num--;
        return c;
    }

    public boolean hasNext() {
        return index != s.length() || num != 0;
    }
}
```