```
class Solution {
    public int balancedStringSplit(String s) {
        int L = 0,R = 0,ans = 0;
        for(char c : s.toCharArray()){
            if(c == 'L')
                L++;
            else
                R++;
            if(L > 0 && L == R){
                ans++;
                L = R = 0;
            }
        }
        
        return ans;
    }
}
```
