1.dfs
```
class Solution {
    String map[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};   
    List res;
    StringBuilder temp;
    public List<String> letterCombinations(String digits) {
        res=new ArrayList<String>();
        temp=new StringBuilder();
        if(digits.length()==0)
            return res;
        dfs(digits,0);
        return res;
    }
    void dfs(String digits,int cur){
        if(cur==digits.length()){
            res.add(temp.toString());
            return;
        }
        for(Character c:map[digits.charAt(cur)-'0'].toCharArray()){
            temp.append(c);
            dfs(digits,cur+1);
            temp.deleteCharAt(temp.length()-1);
        }
    }
        
}
```
2.迭代解法 
```
class Solution {
    String map[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    public List<String> letterCombinations(String digits) {
        List<String> res=new ArrayList<>();
        if(digits.length()==0)
            return res;
        res.add("");
        
        for(Character s:digits.toCharArray()){
            List<String> new_res=new ArrayList<>();
            
            for(String pre_res:res){ 
                for(Character c:map[s-'0'].toCharArray()){
                    new_res.add(pre_res+c);
                }
            }
            res=new_res;
        }
        return res;
    }
}

```
