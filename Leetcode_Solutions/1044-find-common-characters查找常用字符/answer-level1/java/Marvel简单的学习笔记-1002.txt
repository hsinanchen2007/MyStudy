### 解题思路
利用两个哈希表，每个哈希表都是长度为26的int[]数组，都用于记录字符的出现次数。
逐个处理每个单词的每个字符，一个数组temp[]记录当前处理到的单词每个字符的出现次数；另一个数组hash[]记录的是已处理过的所有单词共有字符的出现次数。每处理一个单词，就用temp更新hash，直至最后一个单词处理完毕，hash记录的就是数组中全部单词的共有字符的出现次数，将它们逐一存储到list后返回即可。
初始时，hash的每个值赋为100，因为字符出现次数最多为100。
用temp更新hash的具体操作是，对于每个字符i，当前单词的出现次数为temp[i]，已处理过的单词中的共有字符里，i的出现次数为hash[i]，而此时已处理过的单词又多了一个，那么新的共有字符里i的出现次数为：
`hash[i] = Math.min(hash[i], temp[i]);`

时间复杂度：O(n*m)。n为单词数，m为最长单词的字符数。
空间复杂度：O(1)。两个哈希表大小都为常数。

### 代码

```java
class Solution {
    public List<String> commonChars(String[] A) {
        int[] hash = new int[26];
        int[] temp = new int[26];
        for(int i = 0; i < 26; i++)
            hash[i] = 100;//每个字符出现次数最多100次，因为题目有限制每个单词最多含有100字符
        for(int i = 0; i < A.length; i++)
        {
            for(char c : A[i].toCharArray())
                temp[c - 'a']++;
            for(int j = 0; j < 26; j++)
            {
                hash[j] = Math.min(hash[j], temp[j]);
                temp[j] = 0;
            }
        }
        List<String> list = new LinkedList<String>();
        for(int i = 0; i < 26; i++)
        {
            while(hash[i] > 0)
            {
                list.add(String.valueOf((char)(i + 'a')));
                hash[i]--;
            }
        }
        return list;
    }
}
```