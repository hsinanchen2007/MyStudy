先使用正则表达式找出是否含有小写字母，没有则返回true，然后再对全部是小写和大小写混合的情况进行判断
```
class Solution {
    public boolean detectCapitalUse(String word) {
        int len = word.length();
        if (!word.matches(".*[a-z]+.*")) {
            return true;
        }

        for (int i = 0; i < len; i++) {

            if (Character.isUpperCase(word.charAt(i))&&i!= 0) {
                return false;
            }
        }
        return true;
    }
}
```
