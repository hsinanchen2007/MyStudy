从前往后遍历，每遍历到非空格的地方，就统计一下这个单词的长度，记录到res变量中。

也就是说，首先第一个单词的长度会存到res中，然后第二个单词的长度会存到res中，覆盖掉第一个，在遍历完整个字符串后，自然res中存的就是最后一个单词的长度了。

大概思路是这样，剩下的就是去抠一些case细节了，时间复杂度为O(n)。

```java
class Solution {
    public int lengthOfLastWord(String s) {
        int len = 0, i = 0, res = 0;
      	while(i < s.length()) {
          	len = 0;
          	while(i < s.length() && s.charAt(i) == ' ') i++;
          	while(i < s.length() && s.charAt(i) != ' ') {
              	i++;
              	len++;
            }
          	res = len == 0 ? res : len;
        }
      	return res;
    }
}
```