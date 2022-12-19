很常规的使用双指针解决的一道题，主要要去稍微想想各种case的情况，例如：
```json
1. 左边带空格: "   abc de"
2. 右边带空格: "abc ed  "
3. 左右带空格: "  ab  cd  "
```
我的具体的解法是：在每次进入循环的时候，保证指针i是指向一个单词的开头，而再对i处理完毕后，保证指针j是指向一个单词的结尾后的空格。因此在不越界的情况下，上述的i和j两个指针其实就能完成对一个单词的统计。

```java
class Solution {
    public int countSegments(String s) {
        int count = 0, i = 0, j = 0;
        while(i < s.length()) {
            while(i < s.length() && s.charAt(i) == ' ') i++;
            j = i;
            if(j < s.length()) {
                while(j < s.length() && s.charAt(j) != ' ') j++;
                count++;
                i = j;
            }
        }
        return count;
    }
}
```