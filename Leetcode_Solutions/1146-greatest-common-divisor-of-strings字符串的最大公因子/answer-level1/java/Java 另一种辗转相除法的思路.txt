
> 没想到大佬们精妙的解法，但是想到了另一种辗转相除的思路

将字符串当做数字，然后用 “减法” 替代除法（效率会比较低，但是这题还是1ms过了，数据比较弱），最后求出 ”余数“，按照gcd的写法写就行了

```java
public String gcdOfStrings(String str1, String str2) {
    if(str1.equals(str2)){
        return str1;
    }
    int index1=0,index2=0;
    //用减法替代除法求余数
    while(str1.length()>=str2.length() && index1<str1.length() && index2<str2.length()){
        if(str1.charAt(index1)!=str2.charAt(index2)) return "";
        index2++;
        index1++;
    }
    //gcd(str2,余数)
    return gcdOfStrings(str2,str1.substring(index1,str1.length()));
}
```
