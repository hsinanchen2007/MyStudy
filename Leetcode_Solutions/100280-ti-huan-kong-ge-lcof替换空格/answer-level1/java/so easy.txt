### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String replaceSpace(String s) {
        StringBuffer str=new StringBuffer();
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)==' ')str.append("%20");
            else str.append(s.charAt(i));
        }


        return str.toString();

    }
}
```