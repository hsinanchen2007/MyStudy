### 解题思路
先对原字符串拆分，再逆序拼接，去除尾部空格即可。

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        StringBuilder ans = new StringBuilder("");
        String line[] = s.split("\\s+");
        for (int i = line.length - 1 ; i >= 0 ; i--){
            ans.append(line[i]).append(" ");
        }
        return ans.toString().trim();
    }
}
/*
        String ans = "";
        String line[] = s.split("\\s+");
        for (String word : line){
            ans = word + " " + ans;
        }
        return ans.trim();
*/
```