### 解题思路
此处撰写解题思路
我的思想:
    先将字符串前面n个字符放入到一个数组中，
    然后用一个字符串变量链接n以后的字符
    然后再将n个字符链接到刚才的字符串变量中.
### 代码

```java
class Solution {
    public String reverseLeftWords(String s, int n) {
        char[] str=new char[n];
        for(int i=0;i<n;i++){
            str[i]=s.charAt(i);
        }
        String a="";
        for(int i=n;i<s.length();i++){
            a+=s.charAt(i);
        }
       for(int i=0;i<n;i++){
           a+=str[i];
       }
        return a;
    }
}
```