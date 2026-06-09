### 解题思路
双百

### 代码

```java
class Solution {
    public String replaceSpace(String s) {
        StringBuffer result = new StringBuffer();
        for(int i=0;i<s.length();i++){
            char c = s.charAt(i);
            if(c!=' '){
                result.append(c);
            }else{
                result.append("%20");
            }
        }
        return result.toString();
    }
}
```