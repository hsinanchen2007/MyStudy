### 解题思路
直接交换对应索引位置的元素即可。 击败 100% & 97% ~

### 代码

```java
class Solution {
    public void reverseString(char[] s) {
        char a = 0;
        for (int i = 0; i < s.length / 2; i++) {
            a = s[i];
            s[i] = s[s.length - i - 1];
            s[s.length - i - 1] = a;
        }
    }
}
```