### 解题思路


### 代码

```java
class Solution {
    public String reverseWords(String s) {
        if(s.length() == 0) return s;
        s = s.trim();
        String[] strs = s.split(" ");
        StringBuilder sb = new StringBuilder();
        for(int i=strs.length-1;i >= 0;i--){
            if(!strs[i].equals("")){
                sb.append(strs[i]+" ");
            }
        }
        return String.valueOf(sb).trim();
    }
    
}
```