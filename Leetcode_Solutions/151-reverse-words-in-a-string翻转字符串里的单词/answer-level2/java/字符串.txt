### 解题思路
使用字符串自带的api解决空格问题。然后用空格划分每个空格，最后反向添加。

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        if(s.length() == 0)
            return s;

        s = s.trim(); // 去除前后空格
        s = s.replaceAll("\\s{1,}", " "); //替换多个空格为单个空格

        StringBuilder sb = new StringBuilder();

        String[] strs = s.split(" ");
        
        for(int i = strs.length - 1; i > 0; i--){
            sb.append(strs[i]);
            sb.append(" ");
        }
        sb.append(strs[0]);
        return sb.toString();
    }
}
```