### 解题思路
记录一下重复的字符以及重复次数就好了

### 代码

```java
class Solution {
    public String compressString(String S) {
        int len = S.length();
        if(len < 3){
            return S;
        }
        StringBuilder newStr = new StringBuilder();
        char[] chars = S.toCharArray();
        char cur = chars[0];
        int count = 1;
        for(int i = 1; i < len; i++){
            if(cur == chars[i]){
                count++;
            }else{
                newStr.append(cur).append(count);
                cur = chars[i];
                count = 1;
            }
        }
        newStr.append(cur).append(count);
        if(newStr.length() < len){
            return newStr.toString();
        }
        return S;
    }
}
```