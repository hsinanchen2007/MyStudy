定义变量c记录调整的次数，最后计算调整次数和两个串剩余未遍历字符，小于一个定值。
```java
class Solution {
    public boolean oneEditAway(String first, String second) {
        if(Math.abs(first.length() - second.length()) > 1) return false; // 长度相差超过1，直接错误
        int i = 0, j = 0;
        int c = 0;
        while(i < first.length() && j < second.length()){
            if(first.charAt(i) == second.charAt(j)){
                i++;
                j++;
            }else if(i + 1 < first.length() && first.charAt(i + 1) == second.charAt(j)){
                c++;
                i++;
            }else if(j + 1 < second.length() && first.charAt(i) == second.charAt(j + 1)){
                c++;
                j++;
            }else{
                c++;
                j++;
                i++;
            }
        }
        return c + Math.abs(i - first.length()) + Math.abs(j - second.length()) < 2; // 第一个字符串的剩余和第二个字符串的剩余，以及修改的次数小于2
    }
}
```