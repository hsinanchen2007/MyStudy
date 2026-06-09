### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String replaceSpace(String s) {
        StringBuffer str=new StringBuffer(s);
        return str.toString().replaceAll("\\s", "%20");
    }
}
```