

```

class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        if(s1.length()!=s2.length()){
            return false;
        }
        int a[]=new int[128];
        for(char c:s1.toCharArray()){
            a[c]++;
        }
        for(char c:s2.toCharArray()){
            if(a[c]==0){
                return false;
            }
            a[c]--;
        }
        return true;
    }
}
```




