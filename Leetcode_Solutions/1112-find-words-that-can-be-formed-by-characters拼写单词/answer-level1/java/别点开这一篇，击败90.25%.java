### 解题思路
总的思想就是求每个单词的字母是否完全在chars中，所以直白的思路就是计算一个单词和chars的字母个数，做个对比。

我还写了另一个方法，遍历每个单词的每个字母，然后看他在不在chars中。因为一个单词可能会存在两个同样的字母，而chars只存在一次。

所以用这个方法还需要及时去掉chars中已经对比过的字母。

### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        
        int ans = 0;

        int[] countChars = new int[26];
        for(char c : chars.toCharArray()){
            countChars[c - 'a']++;
        }

        for(String str : words){
            int[] countTemp = new int[26];
            boolean contains = true;
            for(char c : str.toCharArray()){
                countTemp[c - 'a']++;
                if(countTemp[c - 'a'] > countChars[c - 'a']){
                    contains = false;
                    break;
                }     
            }
            
            ans += contains? str.length() : 0;

        }

        return ans;
    }
}
```