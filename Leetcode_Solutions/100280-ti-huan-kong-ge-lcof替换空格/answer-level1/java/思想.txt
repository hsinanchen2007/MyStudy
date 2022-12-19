### 解题思路
此处撰写解题思路
我的思想:
    判断原始的字符串一个一个的取出字符来，判断是否不等于空格的，不等于空格的话另外
创建一个字符串的变量，将这个累加（链接起来的意思），再判断是否为空格，如果为空格的话
那么再把我们想要添加的字符串再次累加起来，这样的话就达到了一个累加的效果！
### 代码

```java
class Solution {
    public String replaceSpace(String s) {
        String str="";
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)!=' '){
                str+=s.substring(i,i+1);
            }else if(s.charAt(i)==' '){
                str+="%20";
            }
        }
        return str;
    }
}
```