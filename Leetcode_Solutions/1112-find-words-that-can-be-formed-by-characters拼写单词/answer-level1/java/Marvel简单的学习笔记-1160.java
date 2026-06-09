### 解题思路
本题的题型在哈希表题库中已出现多次，即给定可用的字母及其个数，判断哪些单词只使用了这些字母并且使用次数不超过该字母可用个数。
字母表chars就是给定的字母及其个数，遍历words的每个单词，只要该单词仅仅使用了字母表内的字母，且使用次数不超过字母个数，累加该单词长度。最终返回所有已掌握单词的长度之和。

时间复杂度：O(n*m)。n为单词个数，m为最长单词的字母数。
空间复杂度：O(1)。

### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        int[] hash = new int[26];
        int[] temp = new int[26];
        for(char c : chars.toCharArray())
            hash[c - 97]++;
        int sum = 0;
        for(String s : words)
        {
            int i;
            for(i = 0; i < 26; i++)
                temp[i] = hash[i];
            char[] current = s.toCharArray();
            for(i = 0; i < current.length; i++)
            {
                if(temp[current[i] - 97] > 0)
                    temp[current[i] - 97]--;
                else break;
            }
            if(i == current.length)
                sum += current.length;
        }
        return sum;
    }
}
```