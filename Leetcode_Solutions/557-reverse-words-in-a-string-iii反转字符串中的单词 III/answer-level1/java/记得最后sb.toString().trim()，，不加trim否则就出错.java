### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String reverse(String str){
        int len=str.length();
        char[] chs=str.toCharArray();
        for(int i=0;i<len/2;i++){
            char tmp=chs[i];
            chs[i]=chs[len-i-1];
            chs[len-i-1]=tmp;
        }
        return String.valueOf(chs);
    }
    public String reverseWords(String s) {
        String[] strs=s.split(" ");
        StringBuilder sb=new StringBuilder();
        for(int i=0;i<strs.length;i++){
            String an=reverse(strs[i]);
            sb.append(an).append(" ");
        }
        return sb.toString().trim();
    }
}
```