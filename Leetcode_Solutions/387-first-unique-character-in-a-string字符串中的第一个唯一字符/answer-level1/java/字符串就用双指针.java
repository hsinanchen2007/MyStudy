```
class Solution {
    public int firstUniqChar(String s) {
        if(s.length() == 0) return -1;
        if(s.length() == 1) return 0;
        
        int i = 0;
        for(int j = 1;j<s.length()&&i<s.length();){
            if((i == j) || (s.charAt(j) != s.charAt(i))){
                j++;
                if(j == s.length()){
                    return i;
                }
            }else{
                i++;
                j = 0;
            }
        }
        return -1;
    }
}
```


入门小白，常规思路，只是代码不太好看，求大神指导优化