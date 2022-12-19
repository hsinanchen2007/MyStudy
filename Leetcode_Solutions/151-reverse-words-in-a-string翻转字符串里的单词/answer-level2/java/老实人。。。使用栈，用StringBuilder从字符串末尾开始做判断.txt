### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        if(s == null || s.length() == 0){
            return "";
        }
        StringBuilder tmp = new StringBuilder();
        StringBuilder ans = new StringBuilder();
        int len = s.length();
        for(int i = len-1; i >= 0; i--){
            if(s.charAt(i) != ' '){
                tmp.append(s.charAt(i));
                if(i == 0 || s.charAt(i-1) == ' '){
                    ans.append(tmp.reverse().toString() + " ");
                    tmp.setLength(0);
                }
            }
            
        }
        if(ans.length() == 0){
            return "";
        }
        ans.delete(ans.length() - 1, ans.length());
        return ans.toString();
    }
}
```