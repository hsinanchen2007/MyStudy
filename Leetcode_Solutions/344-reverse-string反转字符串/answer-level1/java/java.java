```
class Solution {
    public void reverseString(char[] s) {
        int sLength=s.length;
        char temp;
        for(int i=0,j=sLength-1;i<j;i++,j--){
            temp=s[i];
            s[i]=s[j];
            s[j]=temp;
        }
    }
}
```
