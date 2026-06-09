### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String[] findOcurrences(String text, String first, String second) {
        String []sum=new String[text.length()];
        int x=0,y=0;
        String number="";
       for(int i=0;i<text.length();i++){
           if(text.charAt(i)!=' '){
           number+=text.charAt(i);}
         else{
             sum[x++]=number;
             number="";
         }
       }
       sum[x++]=number;
       String []num=new String[x];
       for(int i=0;i<x-2;i++){
           if(sum[i].equals(first)&&sum[i+1].equals(second)){
               num[y++]=sum[i+2];
               i++;
           }
       }
       String []fum=new String[y];
       for(int i=0;i<y;i++)
       fum[i]=num[i];
       return fum;
    }
}
```