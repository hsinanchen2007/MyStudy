### 解题思路

定义int[] length 记录以i位置字符结尾的回文长度，根据长度，可以推算出回文开始字符的坐标，

以 `cbabac` 举例，当i = 1、2 时，回文长度都是1，此时length = {1,1,1,0,0,0}

当 i = 3 时，取a前面的字符b，判断相等，则 i=3位置的回文长度为 length[2] + 2

当 i = 4 时，取`bab`前面的字符`c`,不匹配，此时遍历`baba`，获取以 i = 4 位置结尾的回文长度，并记录到length

### java代码

```java
class Solution {
    public String longestPalindrome(String s) {
        // corner case
        if(s == null || s.length() <= 1){
            return s;
        }
        // 记录以i位置字符结尾的回文长度
        int[] length = new int[s.length()];
        // 以第一个字符结尾的回文长度必然是1
        length[0] = 1;
        // 最长回文的结尾位置
        int maxIdx = 1;
        // 循环计算回文长度
        for(int i = 1 ; i < s.length() ; i++){
            // 锚定 i-1 位置结尾的回文之前的字符
            // "cbabac"，i=4 时，length[i-1] = 3，即"bab"，此时 L=0
            int L = i - 1 - length[i - 1];
            // 如果L有效，匹配 L 和 i 位置字符是否相等
            if(L < 0 || s.charAt(L) != s.charAt(i)){
                // 记录当前匹配的开始位置，从L+1 位置 匹配L～i位置，以i结尾的回文
                int pos = Math.max(0, L + 1);
                // 匹配左坐标
                L = pos;
                // 匹配右坐标
                int R = i;
                // 以i位置结尾的回文长度
                int len = 0;
                // 当坐标不相遇
                while(L <= R){
                    if(s.charAt(L) == s.charAt(R)){
                        // 左右坐标位置相同，根据奇偶增加长度
                        len = len + (L == R ? 1 : 2);
                        L++;
                        R--;
                    } else {
                        // 如果字符不匹配，不形成回文，清空长度，重新匹配
                        len = 0;
                        // 从下一位置开始匹配
                        pos++;
                        // 重置匹配坐标
                        L = pos;
                        R = i;
                    }
                }
                // 记录长度
                length[i] = len;
            } else {
                // 记录长度
                length[i] = length[i - 1] + 2;
            }
            // 最大坐标赋值
            maxIdx = length[maxIdx] < length[i] ? i : maxIdx;
        }
        // 根据最长回文的坐标以及长度切割字符串返回
        return s.substring(maxIdx - length[maxIdx] + 1, maxIdx + 1);
    }
}
```