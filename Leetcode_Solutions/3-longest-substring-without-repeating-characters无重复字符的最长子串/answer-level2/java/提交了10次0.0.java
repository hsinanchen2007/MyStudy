### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
   //获取最长不重复字符串
    public static int lengthOfLongestSubstring(String s) {
        if(s==null||s==""){
            return 0;
        }
        if(s.length()==1){
            return 1;
        }
        String str = "";//暂存字符串
        int maxlen = 0;//最长不重复长度
        int startChar = 0;//暂存字符传起始位置
        for(int i=0;i < s.length();i++){
            if(i==s.length()-1){
            str = s.substring(startChar,i+1);
                break;
            }
            str = s.substring(startChar,i+1);
            //暂存为起始位置到当前位置
            //System.out.println("str:"+str);
            //如果暂存首字符==当前字符，起始值+1，go on
            if(str.contains(s.charAt(i+1)+"")){
                //System.out.println("s:"+s.substring(0,i+1));
                //从重复字符的下一个字符开始
                startChar = s.substring(0,i+1).lastIndexOf(s.charAt(i+1))+1;
                if(str.length()>maxlen){
                    maxlen = str.length();
                }
            }

        }
        if(str.length()>maxlen){
            maxlen = str.length();
        }
        return maxlen;
    }
}
```