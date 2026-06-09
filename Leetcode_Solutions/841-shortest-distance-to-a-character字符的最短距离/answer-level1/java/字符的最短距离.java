### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] shortestToChar(String S, char C) {
        int []count=new int[S.length()];
        int []number=new int[S.length()];
        int min=Integer.MAX_VALUE,x=0;
        for(int i=0;i<S.length();i++){
           if(S.charAt(i)==C){
           count[x++]=i;
           }
        }
        for(int i=0;i<S.length();i++){
            min=Integer.MAX_VALUE;
            for(int j=0;j<x;j++){
                if(Math.abs(count[j]-i)<min)
                min=Math.abs(count[j]-i);
            }
            number[i]=min;
        }
        return number;
    }
}
```