### 解题思路
首先用一个for循环计算得到字符串中的空格数量，通过length+spacenumber*2计算得到结果字符串的长度。然后替换即可

### 代码

```java
class Solution {
    public String replaceSpaces(String S, int length) {
        char[] c=S.toCharArray();
        int spacenumber=0;
        for (int i=0;i<length;i++){
            if (c[i]==' '){
                spacenumber+=1;
            }
        }
        char[] res=new char[length+spacenumber*2];
        int j=0;
        for (int i=0;i<length;i++){
            if (c[i]==' '){
                res[j++]='%';
                res[j++]='2';
                res[j++]='0';
            }else{
                res[j++]=c[i];
            }
        }
        return String.valueOf(res);
    }
}
```