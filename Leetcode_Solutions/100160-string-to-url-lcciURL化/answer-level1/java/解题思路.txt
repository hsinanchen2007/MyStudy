### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String replaceSpaces(String S, int length) {
      return     S.substring(0,length).replace(" ","%20");
      
    }
}
```
1.先截取有效长度
2.替换空格