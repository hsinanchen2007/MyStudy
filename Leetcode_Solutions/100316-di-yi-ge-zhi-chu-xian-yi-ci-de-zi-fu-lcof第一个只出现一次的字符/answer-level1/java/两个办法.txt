常规写题解记录做题思路。
拿到题第一想法是遍历，但心想如果我这样做了自己都会觉得自己不动脑的，所以开始思考只出现一次这个词。
它要明确只出现一次，也就是说需要明确字符出现的次数，那就需要存储每个字符出现了多少次。
明确了需要借助数据结构存储了，所以就需要考虑用哪个数据结构了，很明显，一开始我还是天真的，我选了map。
```java
class Solution {
    public char firstUniqChar(String s) {
        if (s.isEmpty()) return ' ';
        Map<Character, Integer> map = new HashMap<Character, Integer>();
        char ch = ' ';
        for (int i = 0; i < s.length(); i++) {
            ch = s.charAt(i);
            if (!map.containsKey(ch)) {
                map.put(ch, 0);
            } else {
                map.put(ch, 1);
            }
        }
        for (int i = 0; i < s.length(); i++) {
            ch = s.charAt(i);
            if (map.get(ch) == 0) {
                return ch;
            }
        }
        return ' ';
    }
}
```
1. 要注意出口。
2. 用0表示只出现1次，1表示出现多次。当然，这只适合这道题，如果需要知道每个字符出现了多少次还是不要剩这点效率，乖乖从map里面取出来原来的值再加一吧。
3. 全部字符存进map之后，遍历一次map就好了。

确实提交也对了，于是一看效率击败了。。。我都不好意思说，我还节省了一个map的get操作，还以为很聪明了。
于是开始想别的思路，别人应该也是靠存储的，不然遍历只会更慢，于是我考虑能不能换一种数据结构。
有这个思路之后，就是在思考换什么了，这种字符的，除了数组，还能换啥，所以我采取了数组的形式来存储。
```java
class Solution {
    public char firstUniqChar(String s) {
        if (s.isEmpty()) return ' ';
        int[] map = new int[128];
        for (int i = 0; i < s.length(); i++) {
            map[(int)s.charAt(i)]++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (map[(int)s.charAt(i)] == 1) {
                return s.charAt(i);
            }
        }
        return ' ';
    }
}
```
于是，发现效率确实很高，然后顺便看了一眼大佬的题解，再看看排在击败100%的大佬的标程，肯定了一下自己的思路。
这里需要告诉以后回看这题的自己，这里理应第一反应用数组存储的，你已经不是第一次做这种类型的题了，还是得多小心多刷题。