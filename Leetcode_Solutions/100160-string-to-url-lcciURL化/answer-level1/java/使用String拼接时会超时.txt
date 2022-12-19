### 解题思路
使用String拼接时会超时

### 代码

```java
class Solution {
    public String replaceSpaces(String S, int length) {
        String substring = S.substring(0,length);
        String[] splits = substring.split("");
        StringBuffer replace= new StringBuffer();
        for (int i = 0; i <splits.length; i++) {
            if(splits[i].equals(" ")){
                splits[i] = "%20";
            }
            replace.append(splits[i]);
        }
        return String.valueOf(replace);
    }
}
```