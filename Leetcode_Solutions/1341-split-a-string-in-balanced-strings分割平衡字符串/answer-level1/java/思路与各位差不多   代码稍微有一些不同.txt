```
class Solution {
    public int balancedStringSplit(String s) {
        int count = 0;
        int countR = s.length()/2;
        int countL = s.length()/2;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='R'){
                countR--;
            }else{
                countL--;
            }
            if(i!=0&&i%2==1&&countL==countR){
                count++;
            }
        }
        return count;
    }
}
```

