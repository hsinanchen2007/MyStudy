### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void reverseWords(char[] s) {
        int lastBlank=-1;
        for(int i=0;i<=s.length;i++){
            if(i==s.length||s[i]==' ')  //i=s.length是为了翻转最后一个单词
            {
                reverse(s,lastBlank+1,i-1);
                lastBlank=i;
            }
        }
        reverse(s,0,s.length-1);
    }

    private void reverse(char [] s,int L,int R){
        while(L<R){
            char t=s[L];
            s[L++]=s[R];
            s[R--]=t;
        }
    }
}
```