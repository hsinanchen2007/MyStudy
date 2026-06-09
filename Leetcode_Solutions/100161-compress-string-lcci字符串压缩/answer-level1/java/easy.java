### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String compressString(String S) {
        if(S.length() == 0)
            return "";
        StringBuilder sb = new StringBuilder();
        char[] chars = S.toCharArray();      
        int count = 0;
        int index = 0;
        for(int i=0; i<chars.length-1; i++){
            count++;
            if(chars[i] != chars[i+1]){
                sb.append(chars[i]).append(count);
                count = 0;
                index++;
            }
        }
        sb.append(chars[chars.length-1]).append(++count);
        String result = sb.toString();
        return result.length() < S.length() ? result : S;
    }
   


}
```