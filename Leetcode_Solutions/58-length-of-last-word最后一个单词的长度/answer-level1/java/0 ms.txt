### 解题思路
两次循环找到最后一个单词的最后一个字母和开始字母的索引，二者相减就是单词的长度


### 代码

```java
class Solution {
    public int lengthOfLastWord(String s) {
        if(s.equals(""))
            return 0;
        int i=s.length()-1;
        for(;i>=0;i--){
            if(s.charAt(i)!=' ')
                break;
        }
        int j=i;
        for(;j>=0;j--){
            if(s.charAt(j)==' ')
                break;
        }
        return i-j;
    }
}
```