### 解题思路
1、按空格切割 2、倒序遍历，用stringbuilder拼接 3、按空格切，会多余空格，直接跳过 4、拼空格，去掉最后一个

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        String[] str = s.split(" ");
        StringBuilder sb = new StringBuilder();
        for(int i = str.length-1; i>=0; i--){
            if(str[i].equals("")){
                continue;
            }
            sb.append(str[i].replace(" ","")+" ");
        }        
        return sb.toString().trim();
    }
}

```