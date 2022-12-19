### 解题思路
因为java中的String在new 的时候就自动变成了final类型，非常不便于处理。因此一般都是转化为StringBuilder来做
这样本题就很简单了，最简单的思路就是直接利用StringBuilder，重新排一下字符串的顺序，结束。

下面思路来自于剑指offer
举例:"abcdefg"
首先将前n个字符翻转，得到"bacdefg"
然后将后面的字符翻转，得到"bagfedc"
最后将整个字符串翻转，得到"cdefgab"。
这是在不采用额外空间下的做法，在Java里不好整。

如果是char[] 类型的数组作为输入输出，且限定了空间复杂度为O(1)就应该用剑指的方法。
### 代码

```java
class Solution {
    public String reverseLeftWords(String s, int n) {
        StringBuilder sb = new StringBuilder();
        sb.append(reverse(s.substring(0,n)));
        sb.append(reverse(s.substring(n, s.length())));
        return ""+sb.reverse();
    }
    private String reverse(String s){
        StringBuilder sb =  new StringBuilder(s);
        return ""+sb.reverse();
    }
}
```