### 执行用时1ms
本题采用与题目205.同构字符串相同的思路：若两个字符属于一对正确的映射，则它们在各自字符串中第一次出现的位置也相同。
何为正确的映射，即一个元素至多只能映射到一个元素，与此同时，一个元素至多只能被一个元素映射。
本题需要判断pattern中的每个字符是否正确映射到str中的非空单词上。例如示例1中pattern中的每个字符：
a->dog
b->cat
b->cat
a->dog
以上均属于正确的映射。
例如示例2中的每个字符：
a->dog
b->cat
b->cat
a->fish
a映射到了两个元素上，不符合。
示例3同理，a映射到了多个元素。示例4则是一个元素被多个元素映射，同样不符合！
通过观察正确的示例，我们能得出文中开头的思路：若两个字符属于正确的映射，则这两个字符在各自字符串中第一次出现的下标相同。
除此之外，区别于205本题还需要做一点修改，即一个字符在pattern中第一次出现的下标对应的是，一个字符串第一次出现在str中的第几个非空单词，由此我们可以写出一个indexOfWords()方法。
最后，一句话概括该思路就是：pattern中每个字符的indexOf()是否等于str中每个单词的indexOfWords()。

### 代码

```java
class Solution {
    public boolean wordPattern(String pattern, String str) {
        String[] words = str.split(" ");
        int len = pattern.length();
        if(len != words.length) return false;
        for(int i = 0; i < len; i++)
        {
            char a = pattern.charAt(i);
            String b = words[i];
            if(pattern.indexOf(a) != indexOfWords(words,b))
                return false;
        }
        return true;
    }
    private int indexOfWords(String[] a, String b) {
        for(int i = 0; i < a.length; i++)
            if(a[i].equals(b))  return i;
        return -1;
    }
}
```