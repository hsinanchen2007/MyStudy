### 解题思路
利用哈希表记录字符串中每个字母出现的次数，然后找到第一个只出现过一次的字母。
由于只有26个字母，因此使用长度为26的int[]数组即可，将a散列到下标0，将b散列到下标1，如此这般，遍历字符串就可以得到每个字母出现的次数，并将其记录于哈希表中。再遍历一次字符串，找到第一个出现次数为1的字母即可。
时间复杂度：O(n)。
空间复杂度：O(1)。

代码

```java
class Solution {
    public int firstUniqChar(String s) {
        int[] hash = new int[26];
        char[] letter = s.toCharArray();
        int len = letter.length;
        for(int i = 0; i < len; i++)
            hash[letter[i] - 'a']++;
        for(int i = 0; i < len; i++)
            if(hash[letter[i] - 'a'] == 1)
                return i;
        return -1;
    }
}
```

### 改进
执行用时：1ms

由于只有26个字母，则对每个字母做一次检查，检查它们在s中第一次出现和最后一次出现的位置，若这个字母是字符串中的唯一字母，则第一次出现和最后一次出现的位置相同，找出这些唯一字母里排在字符串最前面的。

代码：

```java
class Solution {
    public int firstUniqChar(String s) {
        int index = -1;
        for(char c = 'a'; c <= 'z'; c++)
        {
            int first = s.indexOf(c);
            int last = s.lastIndexOf(c);
            if(first != -1 && first == last)
            {
                if(index == -1) index = first;
                else            index = Math.min(index, first);
            }
        }   
        return index;
    }
}
```