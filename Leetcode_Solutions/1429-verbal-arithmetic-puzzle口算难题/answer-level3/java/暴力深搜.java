用map一直超时，改成数组终于过了，另外搜索顺序从加数的最后一位开始搜应该可以优化很多，但是实现起来太复杂了orz。。
```
class Solution {
    static boolean resu = false;
    public boolean isSolvable(String[] words, String result) {
        resu = false;
        char[] order = new char[10];
        int t = 0;
        int[] map = new int[256];
        char[] hash = new char[200];
        for (String word:words){
            if (word.length()>result.length()) return false;
            for (char c: word.toCharArray()){
                if (map[c] == 0){
                    map[c] = -1;
                    order[t++] = c;
                }
            }
        }    
        for (char c: result.toCharArray()){
            if (map[c] == 0){
                map[c] = -1;
                order[t++] = c;
            }
        }
        dfs(words,result,t,0,map,hash,order);
        return resu;
        
    }
    
    public void dfs(String[] words, String result,int size,int now,int[] map,char[] hash,char[] order){
        if (resu == true) return;
        if (now == size){
            boolean p = check(words,result,map);
            if (p) resu = true;
            return;
        }
        for (int i = 0;i<=9;i++){
            if (hash[i] == 0){
                char c = order[now];
                hash[i] = c;
                map[c] = i;
                dfs(words,result,size,now+1,map,hash,order);
                hash[i] = 0;
            }
        }
    }
    
    
    
    
    public boolean check(String[] words,String result, int[] map){
        for (String word:words){
            if (map[word.charAt(0)]==0) return false;
        }
        if (map[result.charAt(0)]==0) return false;
        int sum = 0;
        for (String word:words){
            sum+=trans(word,map);
        }
        return sum == trans(result,map); 
    }
    public int trans(String s,int[] map){
        int ans = 0;
        for (char c:s.toCharArray()){
            ans*=10;
            ans+=map[c];
        }
        return ans;
    }
}
```
