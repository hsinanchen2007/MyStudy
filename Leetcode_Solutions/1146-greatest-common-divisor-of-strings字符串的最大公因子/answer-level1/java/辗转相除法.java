### 解题思路
辗转相除

### 代码

```java
class Solution {
    //辗转相除——只要求长度的最大公约数即可
    private int find(int x ,int y){
        return y==0?x:find(y,x%y);
    }
 
    public String gcdOfStrings(String str1, String str2) {
        // str1 = A*m   str2 = A*n   A*(m+n)=A*(n+m)
        if (!(str1 + str2).equals(str2 + str1)){return "";}
        return str1.substring(0,find(str1.length(),str2.length()));
    }
}
```