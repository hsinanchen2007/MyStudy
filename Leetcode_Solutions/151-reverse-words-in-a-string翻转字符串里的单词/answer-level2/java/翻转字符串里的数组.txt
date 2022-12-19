### 解题思路
#####注意分割空格的方法（一个或者多个）

### 代码

```java
class Solution {
    public String reverseWords(String s) {

        //方法1：正则式去除多个字符

        // String[]str=s.trim().split("\\s+");
        // StringBuilder sb = new StringBuilder();
        // for(int i=str.length-1;i>=0;i--){
        //      if (sb.length() > 0) {
        //         sb.append(" ");
        //     }
        //     sb.append(str[i]);  
        // }
        // return sb.toString();

        //方法2：
        String[] words = s.trim().split(" ");
        StringBuilder sb = new StringBuilder();
        for (int i = words.length - 1; i >= 0; i--) {
            if ("".equals(words[i])) {
                continue;
            }
            if (sb.length() > 0) {
                sb.append(" ");
            }
            sb.append(words[i]);
        }

        return sb.toString();
        


    }
}
```