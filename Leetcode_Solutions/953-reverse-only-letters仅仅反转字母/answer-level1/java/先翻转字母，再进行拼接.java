### 解题思路
先获取所有的字母，并且将其翻转，然后再将所有的字母与非字母进行拼接。

### 代码

```java
class Solution {
    public String reverseOnlyLetters(String S) {
        //1.先将所有的字符进行翻转
        StringBuilder sb = new StringBuilder();
        for (int i=S.length()-1;i >= 0; i--){
            char c =  S.charAt(i);
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
                sb.append(c);
            }
        }
        
        StringBuilder sb2 = new StringBuilder();
        int count = 0;
        for (int i=0; i < S.length() ; i++){
            char c =  S.charAt(i);
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
                sb2.append(sb.charAt(count++));
            }else {
                sb2.append(c);
            }
        }
        return sb2.toString();
    }
}
```