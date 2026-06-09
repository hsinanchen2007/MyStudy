### 解题思路
- 判断S是以什么开头：I---0;S---N
- 遍历一遍，如果某个元素等于I则加一，如果等于D则减一；
- 判断S以什么结尾：I---前一个元素+1；D---前一个元素-1

### 代码

```java
class Solution {
    public int[] diStringMatch(String S) {
        int k=0;
        int l=S.length();
        int m=1;
        int[] a=new int[S.length()+1];
            if(S.startsWith("I")){
                a[0]=0;
                for(int j=1;j<S.length();j++){
                if(S.valueOf(S.charAt(j)).equals("I")){
                      a[j]=m;
                      m++;
                }else if(S.valueOf(S.charAt(j)).equals("D")){
                 a[j]=l;
                 l--;
                }
                }  
            }else if(S.startsWith("D")){
                a[0]=S.length();
                for(int j=1;j<S.length();j++){
                if(S.valueOf(S.charAt(j)).equals("D")){
                      a[j]=l-1;
                      l--;
                }else if(S.valueOf(S.charAt(j)).equals("I")){
                 a[j]=k;
                 ++k;
                }
                  
            }
            }
            if(S.endsWith("I") ){
                a[a.length-1]=a[a.length-2]+1;
            }
            if(S.endsWith("D") ){
                a[a.length-1]=a[a.length-2]-1;
            }
        return a;
    }
}
```