### 解题思路
暴力解法

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        StringBuilder builder = new StringBuilder("");
        StringBuilder res = new StringBuilder("");
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)!=' '){
                builder.append(s.charAt(i));
            }
            else{
                res.append(builder.reverse().toString());
                builder = new StringBuilder("");
                if(i+1<s.length()){
                    res.append(' ');
                }
            }
        }
        res.append(builder.reverse().toString());

        return res.toString();
    }
}
```