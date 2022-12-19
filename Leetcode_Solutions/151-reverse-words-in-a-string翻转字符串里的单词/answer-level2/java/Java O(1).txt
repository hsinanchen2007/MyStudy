### 解题思路
Java O(1)， 先翻转字符串，再翻转每个单词

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        // O(1)，先翻转整个串，再翻转每个单词（或者先反转每个单词再翻转整个串）
        char[] chars = s.toCharArray();
        int len = chars.length;
        reverse(chars, 0, len-1);
        int i = 0;
        int j = 0;
        while (j < len) {
            while(i < len && chars[i] == ' ') {
                i++;
            }
            j = i;
            while(j < len && chars[j] != ' ') {
                j++;
            }
            reverse(chars, i, j-1);
            i = j;
        }
        return removeSpace(chars);
    }

    private void reverse(char[] chars, int start, int end) {
        int i = start, j = end;
        while(i < j) {
            char tmp = chars[i];
            chars[i] = chars[j];
            chars[j] = tmp;
            i++;
            j--;
        }
    }

    private String removeSpace(char[] chars){
        // j标识原串中符合条件的部分，写入到i指针
        int i = 0, j = 0;
        int length = chars.length;
        while(j < length) {
            while(j < length && chars[j] == ' ') {
                j++;
            }
            while(j < length && chars[j] != ' ') {
                chars[i++] = chars[j++];
            }
            while(j < length && chars[j] == ' ') {
                j++;
            }
            if(j < length) {
                chars[i++] = ' ';
            }
        }
        return new String(chars).substring(0, i);

    }
}
```