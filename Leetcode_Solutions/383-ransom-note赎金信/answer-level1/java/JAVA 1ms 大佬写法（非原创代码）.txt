```
class Solution {
    public boolean canConstruct(String ransom, String magazine) {
        if (magazine.length() < ransom.length()) return false;
        int caps[] = new int[26];
        for (char c : ransom.toCharArray()) {
            int index = magazine.indexOf(c, caps[c - 'a']);
            if (index == -1)
                return false;
            caps[c - 97] = index + 1;
        }
        return true;
    }
}
```
这个写法真的很精妙，首先，是判定magazine的长度是否小于ransom，如果小于那么一定是false；之后，它实际上是遍历了ransom当中的所有字符，然后在caps中保存的并非是magazine中每类字母的个数，而是在对应当前字符c的magazine中每类字母应该遍历的起始位置，如果index == -1则表示在magazine中从caps指定的遍历位置开始没有找到一样的字符，则输出false；这个大佬的解题思路真的很有意思。
**本人新手，欢迎各位大佬的讨论和指正。**
这是我写的一个可能的运行过程，方便理解（ransom=aadd,magazine=cadaad）：
![qq_pic_merged_1577503953023.jpg](https://pic.leetcode-cn.com/8b5b7d396f9e37ac95a2bad94cfcfb9271bda923296a906ee772551e640f013a-qq_pic_merged_1577503953023.jpg)


