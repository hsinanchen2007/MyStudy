### 解题思路
此处撰写解题思路
以下代码没有经过简化 属于刚好实现代码， 简单阐述下思路，就是寻找字符串中相同字母的组数，因为回文数左右字母相同  所以我们只用找有多少组相同的组数，找出相同的后，将它们剔除，再用剩下的字符串进行寻找，如果没有则只用剔除第一个字母，最后根据判断还有没有多余的字母，因为倘若是奇数长度的字符串，那么中间那个字母不用重复，需要加1。
### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
        int sum = 0;
        String ss;
        int a = s.length();
        while(s.length()>0){
            int l = s.length();
            int x = 1;
            for(int i=1;i<l;i++){
                if(s.charAt(0)==s.charAt(i)){
                    x=x+1;
                }
            }
            ss =""+ s.charAt(0);
            s=s.replace(ss,"");
            sum = x/2+sum;
        }
        if(sum*2==a){
            sum = a;
        }else if(sum*2<a){
            sum = sum*2+1;
        }
        return sum;
    }
}
```