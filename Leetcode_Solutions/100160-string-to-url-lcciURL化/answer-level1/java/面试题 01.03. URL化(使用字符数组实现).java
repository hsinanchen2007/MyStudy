### 解题思路
完全按照题目要求，使用字符数组实现，在字符数组上进行操作

### 代码

```java
class Solution {
    public String replaceSpaces(String S, int length) {
        char[] s=S.toCharArray();
        int count=0;
        for(int i=0;i<length;i++){
            char c=S.charAt(i);
            if(c==' '){
                count++;
            }
        }
        char[] res=new char[length+2*count];
        int index=0;
        for(int i=0;i<length;i++){
            if(s[i]==' '){
                res[index++]='%';
                res[index++]='2';
                res[index++]='0';
            }else {
                res[index++]=s[i];
            }
        }
        return new String(res);
    }
}
```