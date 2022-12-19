问题可以分解为3步。求最长公共子序列，构造最长公共子序列，然后根据最长公共子序列构造最短公共超序列。

```
class Solution {
    public String shortestCommonSupersequence(String str1, String str2) {
        
        int[][] state = new int[str1.length() + 1][str2.length() + 1];
        
        for(int i=1; i<=str1.length(); i++){
            for(int j=1; j<=str2.length(); j++){
                if(str1.charAt(i-1) == str2.charAt(j-1)){
                    state[i][j] = state[i-1][j-1] + 1;
                }else{
                    state[i][j] = Math.max(state[i-1][j],state[i][j-1]);
                }
            }
        }
        
        //构造lcd
        String lcds = "";
        
        int lcd = state[str1.length()][str2.length()];
        
        int i = str1.length();
        int j = str2.length();
        
        while(lcd > 0){
            if(str1.charAt(i-1) == str2.charAt(j-1)){
                //list.add(String.valueOf(str1.charAt(i-1)));
                lcds = lcds + String.valueOf(str1.charAt(i-1));
                lcd--;
                i--;
                j--;
            }else{
                if(state[i-1][j] == lcd){
                    i--;
                }else{
                    j--;
                }
            }
        }
        lcds = new StringBuilder(lcds).reverse().toString();
        
        //构造结果
        
        String result = "";
        
        int p1 = 0, p2 = 0;
        
        for(int k = 0; k<lcds.length(); k++){
            for(i = p1; i<str1.length(); i++){
                if(str1.charAt(i) == lcds.charAt(k)){
                    break;
                }
            }
            for(j = p2; j<str2.length(); j++){
                if(str2.charAt(j) == lcds.charAt(k)){
                    break;
                }
            }
            
            result = result + str1.substring(p1,i) + str2.substring(p2,j+1);
            p1 = i+1;
            p2 = j+1;
        }
        result = result + str1.substring(p1,str1.length()) + str2.substring(p2,str2.length());
        
        return result;
    }
}
```