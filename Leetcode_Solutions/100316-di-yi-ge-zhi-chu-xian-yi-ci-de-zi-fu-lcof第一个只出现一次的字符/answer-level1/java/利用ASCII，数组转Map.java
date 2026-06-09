### 解题思路
用一个映射对应字符和字符出现的次数
char转int，用index表示ASCII值，存储出现次数；
从左向右遍历找第一个值为1的字符。

### 代码

```java
class Solution {
    public char firstUniqChar(String s) {
        int[] map = new int[256];
        char[] str = s.toCharArray();
        int len = s.length();
        for(int i = 0 ; i < len ; i++){
            map[(int)str[i]] += 1;
        }
        for(int i = 0 ; i < len ; i++){
            if(map[(int)str[i]] == 1) return str[i];
        }
        return ' ';
    }
}
```