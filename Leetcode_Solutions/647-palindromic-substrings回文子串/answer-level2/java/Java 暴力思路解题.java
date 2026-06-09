### 解题思路
 笔者是个小白  所以用了暴力来解，时间复杂度很高。  不喜勿喷
### 代码

```java
class Solution {
      //这个方法是用来判断是不是回文子串
     public  static  boolean f(String str){
        for (int i = 0; i <str.length()/2 ; i++) {
            if (str.charAt(i)!=str.charAt(str.length()-1-i)){
                return  false;
            }
        }
         return  true;
    }

    public int countSubstrings(String s) {
       int cout=0;
        for (int i = 0; i <=s.length() ; i++) {
            for (int j = i+1; j <=s.length() ; j++) {
               String a= s.substring(i,j);//循环截取字符
               if (f(a)){
                   cout++;
               }
            }
        }
        return  cout;
    }
}
```