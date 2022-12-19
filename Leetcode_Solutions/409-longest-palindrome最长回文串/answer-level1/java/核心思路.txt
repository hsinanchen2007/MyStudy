### 解题思路

对于每个字符c：
如果c的总数量为偶数个，则所有的字符c都可用，回文串左右各 length(c)/2 个字符即可
如果c的总数量为奇数个，则所有的字符c都可用，且只能有一次的奇数个c，位于回文串中间即可
注意：奇数个的字符c只能出现一次

### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
        // 对于每个字符c，
        // 如果c的总数量为偶数个，则所有的字符c都可用，回文串左右各 length(c)/2 个字符即可
        // 如果c的总数量为奇数个，则所有的字符c都可用，且只能有一次的奇数个c，位于回文串中间即可
        // 注意：奇数个的字符c只能出现一次

        int[] count = new int[128];
        for (char c : s.toCharArray()) {
            count[c] ++;
        }

        int result = 0;
        for (int len : count) {
            if (len % 2 == 0) {
                result += len;
            }else if(len % 2 == 1) {
                if (result % 2 == 0) {
                    result += len;
                }else {
                    result += len - 1;
                }
            }
        }
        return result;
    }
}
```