### 解题思路
用长度为26的int[]数组作为哈希表，统一使用小写（大写字母转换为小写），记录每个字母出现的次数。
首先根据licensePlate构造好哈希表，再对words的每个单词进行检查。
若license所有字母包括个数（忽略字母以外的数字空格等字符）都匹配上，再判断单词长度，从而得到最短完整单词；若有多个最短完整词，输出最靠前的一个。

### 代码

```java
class Solution {
    public String shortestCompletingWord(String licensePlate, String[] words) {
        int[] hash = new int[26];
        int[] temp = new int[26];//hash[]数组的拷贝，用于选取最短完整词
        int cnt1 = 0;
        String output = "";
        int shortest = 16;//记录当前最短完整词的长度
        
        char[] license = licensePlate.toCharArray();
        for(char c : license)
        {
            if(c >= 'A' && c <= 'Z')    c += 32;
            if(c >= 'a' && c <= 'z')
            {
                hash[c - 'a']++;
                cnt1++;
            }
        }
        for(String w : words)
        {
            char[] word = w.toCharArray();
            int len = word.length;
            int cnt2 = cnt1;
            for(int i = 0; i < 26; i++)
            	temp[i] = hash[i];
            for(char c : word)
            {
                if(c >= 'A' && c <= 'Z')    c += 32;
                if(temp[c - 'a'] > 0)
                {
                    temp[c - 'a']--;
                    cnt2--;
                }
                if(cnt2 == 0 && len < shortest)
                {
                    shortest = len;
                    output = w;
                    break;
                }
            }    
        }
        return output;
    }
}
```