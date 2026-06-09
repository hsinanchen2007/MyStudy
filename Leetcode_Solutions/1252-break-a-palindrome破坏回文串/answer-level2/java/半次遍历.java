### 解题思路
题目不难，但是情况较多。。多调试就能做出来的

### 代码

```java
class Solution {
    public String breakPalindrome(String palindrome) {
        char[] pal = palindrome.toCharArray();
        int length = pal.length;
        if (length == 0 || length == 1) {
            return "";
        }
        // 遇到第一个不为a的字符修改成a即可
        // 由于是回文串，只需要扫描一半即可
        // 还要考虑全a情况和 aabaa这种情况
        int maxBound = (length&1)==1? (length-2)>>1 : (length-1)>>1;
        for(int i = 0; i <= maxBound; i++) {
            if(pal[i] != 'a') {
                pal[i] = 'a';
                return new String(pal);
            }
        }
        // 如果跳出循环，说明前半段一定都是a，这样的话若是长度奇数，修改中间那位一定没有效果，所以只需要把最后一位改成b即可
        pal[length-1] = 'b';
        return new String(pal);
    }
}
```