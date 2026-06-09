### 解题思路
两个变量指向头尾

### 代码

```java
class Solution {
    public int[] diStringMatch(String S) {
       int min=0,max=S.length();
       int []s=new int[max+1];
       int j=0;
        char []a=S.toCharArray();
       for(int i=0;i<S.length();i++){
           if(a[i]=='I'){
               s[j++]=min;
               min++;
           }
            if(a[i]=='D'){
                s[j++]=max;
                max--;
            }    
       }
       s[j]=min;
       return s; 
    }
}
```