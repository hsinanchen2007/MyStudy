主要思想是把字符映射到一个数组里面
```
class Solution {
    public String shortestCompletingWord(String licensePlate, String[] words) {
        int[] license = new int[26];
        for(char c : licensePlate.toCharArray()){
            if(c >= 'a' && c <= 'z')
                license[c - 'a']++;
            else if(c >= 'A' && c <= 'Z')
                license[c - 'A']++;
        }
        String res = null;
        for(String word : words){
            if(isContains(license,word))
                if(res == null || word.length() < res.length())
                    res = word;
        }
        
        return res;
    }
    
    private boolean isContains(int[] license,String word){
        int[] ans = new int[26];
        for(char c : word.toCharArray()){
            if(c >= 'a' && c <= 'z')
                ans[c - 'a']++;
            else if(c >= 'A' && c <= 'Z')
                ans[c - 'A']++;
        }
        
        for(int i = 0;i < 26;i++)
            if(ans[i] < license[i])
                return false;
        return true;
    }
}
```
