### 解题思路
执行用时 :1 ms, 在所有 java 提交中击败了100.00%的用户
内存消耗 :34.6 MB, 在所有 java 提交中击败了93.44%的用户
### 代码
```java
class Solution {
    public boolean detectCapitalUse(String word) {
       char[] chars = word.toCharArray();
        int len = chars.length;
        if (len == 1) {
            return true;
        }
        if (len == 2 ) {
            if (chars[0] >'a'){
                return chars[1] >='a';
            }else {
                return true;
            }
        }
        char first = chars[0];
        // 大写字母开头
        if (first >= 'A' && first <='Z'){
            for (int i = 2; i <len ; i++) {
                // 第二个也是大写字母a
                if (chars[1] <= 'Z') {
                    if (chars[i] > 'Z') {
                        return false;
                    }
                }else {
                    if (chars[i] < 'a') {
                        return false;
                    }
                }
            }
        }
        //非大写字母开头
        else{
            for (int i = 1; i <len ; i++) {
                if (chars[i] < 'a') {
                    return false;
                }
            }
        }
        return true;
    }
}
```