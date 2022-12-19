### 解题思路
此处撰写解题思路
我的思路:
  一直纳闷了很久才想出来的字符和整数转换，字符转换整数，太菜了！
  先将字符串一个一个的拆开为字符数组，然后创建一个连接的字符的字符串
  随后，通过赋值好的字符数组进行遍历，如果数组中的字符是大写的话就进行字符+32为一个整形放入到整形的
  变量，再通过整形变量的强制转换成字符(65-'a'),再将这个字符转换成字符串，用链接字符串的变量进行链接
  否是不是大写的话直接将字符转换成字符串然后进行链接！
  最后将链接好的字符串进行返回即可；
### 代码

```java
class Solution {
    public String toLowerCase(String str) {
      char a[]=new char[str.length()];
      int j=0;
      for(int i=0;i<str.length();i++){
            a[j]=str.charAt(i);
            j++;
      }

    String z="";
      for(int i=0;i<j;i++)
    {
        if(a[i]>='A' && a[i]<='Z'){
                    char k=a[i];
                    int b=k+32;
                    char c=(char)b;
                    z+=String.valueOf(c);
        }else{
                     char k=a[i];
                    z+=String.valueOf(k);
        }
    }   
      return z;
    }
}
```