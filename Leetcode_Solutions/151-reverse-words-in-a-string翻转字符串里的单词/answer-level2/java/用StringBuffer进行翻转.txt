### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        if(s == null || s.length() == 0){
            return s;
        }
        String[] sub = s.split(" ");
        for(int i = 0; i < sub.length; i++){
            sub[i] = sub[i].trim();
        }
        StringBuffer sb = new StringBuffer();
        for(int i = sub.length - 1; i >= 0; i--){
            if(sub[i] == "" || "".equals(sub[i])){
                continue;
            }
            sb.append(sub[i] + " ");
        }
        String res = sb.toString();
        if(res.length() > 0){
            res = res.substring(0, res.length()-1);
        }
        return res;
    }
}
```