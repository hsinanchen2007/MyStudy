刚开始看错题目没有思路，后来看到大家的题解，才发现我看错了
没错，即使看对了，也没思路
站在大家的肩膀上完善一下注释以及一些小细节

思路：
1. 前提条件为`chars`当中的每一个字符只能使用一次，这也决定了，**每个字符出现的次数必须符合要求，而不是出现一次就符合要求**
2. 如果`words`数组中每个字符串`word`的每个字符的出现次数**都满足**`小于等于`该字符在`chars`出现的次数，那么称该`word`则符合统计条件
3. 需要一个工具来帮助我们统计每个字符的出现次数，可以理解为每个字符的`计数器`。
    - 首先想到的就是`HashMap`，`key`为某个字符，`value`为出现的次数
    - 其他答主巧妙的提出了可以使用`int[26]`来统计每个字符的出现次数。因为题目说只包含`小写字母`，所以可以直接声明一个长度为`26`的数组。下标`[0,25]`分别代表`[a,z]`，值为出现的次数。关于如何存储至指定的下标，我们可以借助`ASCII码`。字符可以转换为相应的整数，比如`[a,z]`对应`[97,122]`, 可以看出代表的数字都是递增1的，所以我们可以把字符`a`当做一个基准，即可以使用`当前字符-'a'`来获得数组下标。比如当前字符为`a`，那么`'a'-'a'`转换为数字即`97-97`结果为0，也就是我们需要存储的数组下标。`ASCII码`如下图所示（百度找的）
    ![image.png](https://pic.leetcode-cn.com/3cbd0eaddf7de4898069bf7636a37c6801d061e95c980249cfe0b10c0e324ab3-image.png)

分析完毕，以下为代码，包含`hashMap`版本以及`数组版本`
```java
/**
 * 分析
 * 1.判断直接返回0的条件
 *     1.1-words为空或长度为0
 *     1.2-chars为空或者长度为0
 * 2.判断words中某个word不用参与统计的条件
 *     2.1-word为空或者长度为0
 *     2.2-word的长度>chars的长度
 * 3.判断chars是否能拼成words，需要记录words的每个字符出现的次数以及chars每个字符出现的次数
 * 如果words中每个字符出现的次数都小于等于该字符在chars中出现的次数，那么则可以拼成该字母，否则不能
 * 4.存储容器
 *     3.1-hashMap：key为每个字符，value为个数
 *     3.2-数组，长度为26，因为都是小写字母，下标0的元素代表'a'出现的次数，下标1的元素代表'b'出现的次数...下标25的元素代表'z'出现的菜蔬
 *     下标 = 字符 - 'a'，例如'a' - 'a' = 0，'b' - 'a' = 1
 */
class Solution {

    static final int SIZE = 26; // 数组大小为26-26个小写字母

    /**
     * 数组版本
     * @param words
     * @param chars
     * @return
     */
    public int countCharacters(String[] words, String chars) {
        /* 如果words为空或者长度为0
           如果chars为空或者长度为0
           直接返回0 */
        if (words == null || words.length == 0 || chars == null || chars.length() == 0)
            return 0;

        int spellOut = 0; // 可以拼出的字母的长度
        // boolean canSpell;    // 标识位，用来标识能否拼出
        int[] wordCounter;    // words字符计数器
        int[] charCounter = new int[SIZE];    // chars字符计数器

        /* 记录chars中每个字符出现的次数 */
        for (char c: chars.toCharArray()) {
            charCounter[c - 'a'] ++;
        }

        /* 记录words中的每个word的每个字符的出现的次数
           并与chars计数器比较 */
        loop:  // 标签，用来处理内部循环与外部循环之间的通信，如不使用，可以在循环使用一个boolean类型的变量来判断是否符合条件
        for (String w: words) {
            /* 如果w为空或者w长度为0或者w的长度>chars的长度，不参与统计 */
            if (w == null || w.length() == 0 || w.length() > chars.length())
                continue;

            wordCounter = new int[SIZE];
            // flag = true;
            for (char c: w.toCharArray()) {
                // 判断该字符是否在chars中出现
                if (charCounter[c - 'a'] == 0) continue loop; // canSpell = false;
                wordCounter[c - 'a'] ++;
            }
            /* 判断每个word的字符出现次数是否至少在chars中同样出现
               即word的字符出现次数是否<=chars出现的次数 */
            for (int i = 0; i < SIZE; i ++) {
                if (wordCounter[i] > charCounter[i])
                    continue loop;  // canSpell = false亦可；
            }
            //if (canSpell)
            spellOut += w.length();
        }
        return spellOut;
    }

    /**
     * hashMap版本
     * @param words
     * @param chars
     * @return
     */
    public int countCharacters2(String[] words, String chars) {
        /* 如果words为空或者长度为0
           如果chars为空或者长度为0
           直接返回0 */
        if (words == null || words.length == 0 || chars == null || chars.length() == 0)
            return 0;

        int spellOut = 0; // 可以拼出的字母的长度
        // boolean canSpell;    // 标识位，用来标识能否拼出
        Map<Character, Integer> wordCounter;    // words字符计数器
        Map<Character, Integer> charCounter = new HashMap<>();    // chars字符计数器

        /* 记录chars中每个字符出现的次数 */
        for (char c: chars.toCharArray()) {
            charCounter.put(c, charCounter.getOrDefault(c, 0) + 1);
        }

        /* 记录words中的每个word的每个字符的出现的次数
           并与chars计数器比较 */
        loop:  // 标签，用来处理内部循环与外部循环之间的通信，如不使用，可以在循环使用一个boolean类型的变量来判断是否符合条件
        for (String w: words) {
            /* 如果w为空或者w长度为0或者w的长度>chars的长度，不参与统计 */
            if (w == null || w.length() == 0 || w.length() > chars.length())
                continue;

            wordCounter = new HashMap<>();
            // flag = true;
            for (char c: w.toCharArray()) {
                // 判断该字符是否在chars中出现
                if (!charCounter.containsKey(c)) continue loop; // canSpell = false;
                wordCounter.put(c, wordCounter.getOrDefault(c, 0) + 1);
            }
            /* 判断每个word的字符出现次数是否至少在chars中同样出现
               即word的字符出现次数是否<=chars出现的次数 */
            for (char c: wordCounter.keySet()) {
                if (wordCounter.get(c) > charCounter.getOrDefault(c, 0))
                    continue loop;  // canSpell = false亦可；
            }
            //if (canSpell)
            spellOut += w.length();
        }
        return spellOut;
    }
}
