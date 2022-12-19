### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String countAndSay(int n) {
        String res = "1";
        for(int i = 1; i < n; i++){
          res = temp(res.toCharArray());
        }
        return res;    
    }

    private String temp(char[] chars) {
        StringBuilder sb = new StringBuilder();
        char ch = chars[0];
        int temp = 1, i = 1;
        while (i < chars.length){
            if (chars[i] == ch) {
                temp++;
            } else {
                sb.append(temp).append(chars[i - 1]);
                ch = chars[i];
                temp = 1;
            }
            i++;
        }
        sb.append(temp).append(chars[i - 1]);
        return String.valueOf(sb);
    }
}

```