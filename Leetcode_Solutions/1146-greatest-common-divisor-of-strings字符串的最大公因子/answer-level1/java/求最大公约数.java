### 解题思路
首先如果存在最长字符串X,那么必定存在一个值使得str1=aX,str2=bX;
那么str1+str2一定等于str2+str1,即aX+bX=bX+aX,
所以str1+str2==str2+str1是存在X的充分必要条件
aX.length=str1.length,bX.length=str2.length;
X的长度为str1.length与str2.length的最大公约数
最终结果即为
str1.substring(0,gcd(str1.length(),str2.length()))或str2.substring(0,gcd(str1.length(),str2.length()))
### 代码

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        if(!(str1+str2).equals(str2+str1)){
            return "";
        }
        return str1.substring(0,gcd(str1.length(),str2.length()));
    }
    //求最大公约数使用的是更相减损法
    //循环求最大公约数
    public int gcd(int a,int b){
        while(a%b!=0){
            int temp=a%b;
            a=b;
            b=temp;
        }
        return b;
    }
    //递归
    public int gcd1(int a,int b){
        if(a%b==0){
            return b;
        }
        return gcd(b,a%b);
    }
}
```