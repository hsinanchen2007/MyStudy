
```java
class Solution {
    public String replaceSpace(String s) {
        //input check 
        if(s==null || s.length()==0)
            return s;
        int n = s.length();
        //统计空格数量
        int spaceNum = 0;
        for(int i=0; i<n; i++){
            if(s.charAt(i)==' ')
                spaceNum++;
        }
        //替换空格后一共有n+2*spaceNum个字符
        char[] chs = new char[n+2*spaceNum];
        int j=0;
        for(int i=0; i<n; i++){
            char ch = s.charAt(i);
            if(ch!=' ')
                chs[j++] = ch;
            else{
                chs[j++] = '%';
                chs[j++] = '2';
                chs[j++] = '0';
            }
        }
        return new String(chs);
    }
}
```