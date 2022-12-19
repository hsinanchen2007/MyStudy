

```
class Solution {
    public int compress(char[] chars) {
        int n=chars.length;
        int count=1;
        String s="";
        for(int i=0;i<n-1;i++){
            if(chars[i]==chars[i+1]){
                count++;
            }else{
                if(count==1){
                    s=s+chars[i];
                }else{
                    s=s+chars[i]+count;
                    count=1;
                }
            }

        }
        if(count==1){
            s=s+chars[n-1];
        }else{
            s=s+chars[n-1]+count;
        }
        for(int i=0;i<s.length();i++){
            chars[i]=s.charAt(i);
        }

        return s.length();
    }
}
```

