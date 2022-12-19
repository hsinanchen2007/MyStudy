### 解题思路
本题需要你理解什么是外观数列，然后想办法构造外观数列。我用的递归，核心代码是for循环里面的内容。


### 代码

```java
class Solution {
    public String countAndSay(int n) {
        String str = "1";
        int m = 0;
        str = getStr(str,n,m);
        return str;

    }
    public static String getStr(String str,int n,int m){
        m++;
        String s = "";
        if(m == n){
            return str;
        }
        else{
            for(int i = 0;i < str.length();){
                int j = i;
                int c = 0;
                while(j<str.length() && str.charAt(i) == str.charAt(j)){
                    j++;
                    c++;
                }
                s = s + c + str.charAt(i); 
                i = j;

            }
            return getStr(s,n,m);
        }
    }
}
```