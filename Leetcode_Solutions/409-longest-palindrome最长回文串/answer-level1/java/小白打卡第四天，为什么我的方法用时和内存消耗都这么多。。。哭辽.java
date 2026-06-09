### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
        int res=0;
        int flag=0;//判断是否有大于2的奇数个字母的数
        int flag2=0;//判断是否有只有一个字母的数
        int i=0;
        int num;
       a:for(;i<s.length();i++){
            num=1;
            for(int j=0;j<i;j++){
                if(s.charAt(j)==s.charAt(i)){
                   // i++;
                    continue a;
                }
            }
            for(int x=i+1;x<s.length();x++){
                if(s.charAt(i)==s.charAt(x)){
                    num++;
                    res++;
                }
            }
            if(num%2==0&&num>=2){
                res++;
            }
           if(num%2==1&&num>=2){
               flag=1;
           }
           if(num==1){
               flag2=1;
           }
        }
        if(flag==1||flag2==1){
            res++;
        }
        return res;
    }
}
```