### 解题思路
此处撰写解题思路
我的思路：
    我们用一个字符=串赋值为我们想要替换的字符串，另外再来一个字符串用来链接字符的
循环到字符串的长度，然后取出字符串的每一个字符判断是否等于（点的）时候我们将用来链接字符串的变量将要替换的链接起来
如果不等余点的时候，我们将字母都链接起来，这样的话就能构成一个完整的字符串了！
### 代码

```java
class Solution {
    public String defangIPaddr(String address) {
        String str="[.]";
        String s="";
        for(int i=0;i<address.length();i++){
            if(address.charAt(i)=='.'){
                s+=str;
            }else{
                s+=address.substring(i,i+1);
            }
        }
        return s;
    }
}
```