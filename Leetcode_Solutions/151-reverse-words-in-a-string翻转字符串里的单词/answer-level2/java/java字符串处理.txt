### 解题思路
感觉我这个思路还算是比较简洁（至少比官方题解简洁）

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        if(s==null||s.length()==0) return s;
        int len =s.length();
        StringBuilder sb=new StringBuilder();
        int index=len-1;
        while(index>=0){
            while(index>=0&&s.charAt(index)==' ')
                index--;
            int temp=index;
            while(index>=0&&s.charAt(index)!=' ')
                index--;
            if(index!=temp){
                sb.append(s.substring(index+1,temp+1));
                sb.append(" ");
            }
        }
        if(sb.length()>0)
            return sb.toString().substring(0,sb.length()-1);
        else return "";
    }
    
}
```