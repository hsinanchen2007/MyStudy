### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String replaceSpace(String s) {
        char[] c = s.toCharArray();
        StringBuffer sb = new StringBuffer();
        for(int i = 0;i<c.length;i++){
            if(c[i]==' '){
                sb.append("%20");
            }else{
                sb.append(c[i]);
            }
        }
        return sb.toString();
    }
}
```