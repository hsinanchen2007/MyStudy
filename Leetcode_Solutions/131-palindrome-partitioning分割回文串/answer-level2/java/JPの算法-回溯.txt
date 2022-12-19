```
class Solution {
    List<List<String>> ans = new ArrayList<>();

    public List<List<String>> partition(String s) {
        dfs(s,new ArrayList<>(),0);
        return ans;
    }

    public void dfs(String s,List<String> temp,int index){
        if(index==s.length()){
            ans.add(new ArrayList<>(temp));
            return ;
        }
        for(int i=index;i<s.length();i++){
            if(isPalindrome(index,i,s)){
                temp.add(s.substring(index,i+1));
                dfs(s,temp,i+1);
                temp.remove(temp.size()-1);
            }
        }
    }

    public boolean isPalindrome(int start,int end,String s){
        while(start<end){
            if(s.charAt(start)!=s.charAt(end))
                return false;
            start++;
            end--;
        }
        return true;
    }
}
```
