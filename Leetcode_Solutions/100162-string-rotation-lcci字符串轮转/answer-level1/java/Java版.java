刚开始没有认真看题目，还以为是乱序的两字符串，直接就桶排序下去，后来返回来看的时候，发现字符串是通过旋转后的，那么这样的话，我们可以直接两个s1相加，然后判断s2是否包含在里面，如果包含在里面，就说明可以通过旋转得到。
### 代码

```java
class Solution {
    /*用桶排序来接受字符，由于题目中没有说是只包含小写字母，所以我直接用个长度为128来存储(随手写的长度)
    *代码中我是用alpha数组去接受s1字符串中的字符，然后用s2字符串相应去减掉s1字符串,如果alpha中的数据都为0，则说明两者所含字符相同(数量和种类)。
    */
    public boolean isFlipedString(String s1, String s2) {
        if(s1.length() != s2.length())
            return false;
        if(s1.equals(s2))
            return true;
        int[] alpha = new int[128];
        char[] c = s1.toCharArray();
        for (char cc : c) {
            alpha[cc - '0']++;
        }
        char[] c1 = s2.toCharArray();
        for (char cc1 : c1) {
            alpha[cc1 - '0']--;
        }
        for (int i = 0; i < alpha.length; i++) {
            if(alpha[i] != 0)
                return false;
        }
        return true;
    }
}
```
下面的代码中我用了StringBuffer，虽然说可以不用StringBuffer，但用字符串的相加，我个人觉得尽量用StringBuffer,因为StringBuffer的效率高于String。
```java
class Solution {
    public boolean isFlipedString(String s1, String s2) {
        if(s1.length() != s2.length())
            return false;
        if(s1.equals(s2))
            return true;
        StringBuffer s = new StringBuffer();
        s.append(s1).append(s1);
        return s.toString().contains(s2);
    }
}
```