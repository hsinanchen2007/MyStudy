```
class Solution {
    public boolean isPalindrome(String s) {
        s = s.toLowerCase().replaceAll("[^a-zA-Z0-9]", "");
        String ss = new StringBuffer(s).reverse().toString();
        if(s.equals(ss)){
            return true;
        }
        else return false;
    }
}
```
特别感谢LeetCode刷题群大佬们的帮忙找出正则表达式的错误！！！非常感谢

群号：812791932