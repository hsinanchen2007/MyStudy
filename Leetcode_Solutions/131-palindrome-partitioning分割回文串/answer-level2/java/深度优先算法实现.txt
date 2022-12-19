```
class Solution {
    private List<List<String>> ans = new ArrayList();
    private List<String> list = new ArrayList();
    
    public List<List<String>> partition(String s) {
        if(s.length() == 0) return ans;
        
        solve(0, s);
        return ans;
    }
    
    private void solve(int index, String str){
        if(index == str.length()){
            ans.add(new ArrayList(list));
            return;
        }
        
        for(int i=index+1; i<=str.length(); i++){
            String val = str.substring(index, i);
            if(isHui(val)){
                list.add(val);
                solve(i, str);
                list.remove(list.size()-1);
            }
        }
        
    }
    
    private boolean isHui(String str){
        int left = 0, right = str.length()-1;
        while(left < right){
            if(str.charAt(left ++) != str.charAt(right--))
                return false;
        }
        
        return true;
    }
}
```