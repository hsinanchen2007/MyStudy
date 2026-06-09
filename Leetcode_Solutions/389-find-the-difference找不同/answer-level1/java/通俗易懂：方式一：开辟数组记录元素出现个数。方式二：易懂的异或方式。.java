```
class Solution {
    // 方式二：异或，两个相同元素异或之后的值是0，0和x(任何数)异或等于x，还有一点非常重要：就是不管两个相同的数是在什么时候异或的，最终的结果都会存在0
    // 我举个例子：假如有6个数字：2 3 4 4 3 2， 不管是2^3^4^4^3^2 还是我们经过处理之后组合起来 (2^2)^(3^3)^(4^4)结果都是一样的，不会影响结果
    // 那我们想下本题两个字符串中的字符，s和t中相同的字符都存在两个，将他们全部异或之后肯定为0，然后其中还有一个多出来的就成了0^x=x，从而得到结果，不知道大家理解没
    public char findTheDifference(String s, String t) {
        char result = 0;
        for (int i = 0; i < s.length(); i++){
            result ^= s.charAt(i);
        }
        for (int i = 0; i < t.length(); i++){
            result ^= t.charAt(i);
        }

        return result;
    }
    // 方式一：通过维护一个大小为26的数组，在数组中记录每个字符出现的次数，然后遍历t减去相应的元素个数，如果出现-1的情况说明s字符串中不存在的字符
    public char findTheDifference1(String s, String t) {
        int[] record = new int[26];
        int lenS = s.length();
        int lenT = t.length();
        for (int i = 0; i < lenS; i++){
            record[s.charAt(i) - 'a'] += 1;
        }

        for (int i = 0; i < lenT; i++){
            record[t.charAt(i) - 'a'] -= 1;
            if (record[t.charAt(i) - 'a'] < 0) return t.charAt(i);

        }

        return ' ';
    }
}
```
