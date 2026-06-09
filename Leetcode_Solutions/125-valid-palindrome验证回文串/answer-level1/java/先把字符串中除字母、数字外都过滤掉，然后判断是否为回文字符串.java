```
class Solution {
    public  boolean isPalindrome(String s) {
        return isOk(filter(s));
    }

    /** 过滤掉除数字、字母外的字符 */
    private String filter(String s) {
        StringBuilder sb = new StringBuilder();
        s = s.toUpperCase();//把字符串中的字符都设置为大写的
        for (char c : s.toCharArray()) {
            if (Character.isDigit(c) || Character.isLetter(c)) {
                sb.append(c);
            }
        }
        return sb.toString();
    }

    /** 用StringBuilder的reverse()方法来判断一个字符串是否为回文的 */
    private boolean isOk(String s) {
        return s.equals(new StringBuilder(s).reverse().toString());
    }
}
```
