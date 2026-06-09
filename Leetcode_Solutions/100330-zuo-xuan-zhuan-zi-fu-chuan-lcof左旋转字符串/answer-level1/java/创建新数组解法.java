```
class Solution {
    public String reverseLeftWords(String s, int n) {
           int count=0;
        char[] ch=s.toCharArray();
        char[] newch=new char[ch.length];
        for(int i=0;i<=ch.length-n-1;i++){
            newch[i]=ch[i+n];
            count=i;
            }
        for(int i=0;i<n;i++){
            newch[count+i+1]=ch[i];
            }
        String news=String.copyValueOf(newch);
        return news;
}}
```
也可以直接substring。
