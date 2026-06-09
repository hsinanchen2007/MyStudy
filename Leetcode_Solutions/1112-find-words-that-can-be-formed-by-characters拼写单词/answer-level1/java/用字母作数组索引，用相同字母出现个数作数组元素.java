int[26]这个骚操作学习到了，leetcode第3题中官方解法的最后一种里就给出了这种思路。[3](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/wu-zhong-fu-zi-fu-de-zui-chang-zi-chuan-by-leetcod/)
数组可以当一个小HashMap来用，实在是秒！
常用的表如下所示：
1. int [26] 用于字母 ‘a’ - ‘z’ 或 ‘A’ - ‘Z’
2. int [128] 用于ASCII码
3. int [256] 用于扩展ASCII码


``` java
class Solution {
    public int countCharacters(String[] words, String chars) {
        int ans = 0;
        // 构造一个数组对应chars，索引对应字母，元素存该字母的个数,字母个数不可能超过26
        int[] c = new int[26];
        for (int i = 0; i < chars.length(); i++) {
            c[chars.charAt(i)-'a'] ++;
        }

        // 构造一个数组对应 words 中的每一个 word
        for (String word : words) {
            int[] w = new int[26];
            int i = 0;
            for (i = 0; i < word.length(); i++) {
                int index = word.charAt(i) - 'a';
                w[index] ++;
                // 对应位置 w > c  说明 word 不可能拼写出来
                if (w[index] > c[index]){
                    break;
                }
            }
            if (i == word.length()) ans += i;
        }
        return ans;
    }
}
```
