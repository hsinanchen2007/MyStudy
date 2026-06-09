### 解题思路
无脑暴力，碰到空格就插字符串，复杂度O(n^2)

### 代码

```java
class Solution {
    public String replaceSpace(String s) {
        StringBuffer res=new StringBuffer();
        for(int i=0;i<s.length();i++){
            char c=s.charAt(i);
            if(c==' '){
                res.append("%20");
            }
            else{
                res.append(c);
            }
        }
        return res.toString();
    }
}
```