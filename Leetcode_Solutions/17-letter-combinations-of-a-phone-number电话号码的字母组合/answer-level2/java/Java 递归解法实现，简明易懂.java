
```
public List<String> letterCombinations(String digits) {
        ans.clear();
        if( null ==  digits || digits.isEmpty()) return ans;
        n = digits.length();
        word = new char[n];
        dfs(digits,0);
        return ans;
    }

    String[] d = new String[]{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int n;
    List<String> ans = new LinkedList<>();
    char[] word;

    void dfs(String digits,  int cur){
        if (cur >= n) {
            String item = new String(word);
            ans.add(item);
        }else{
            String s = d[digits.charAt(cur)-'0'];
            for(int i=0;i< s.length();i++){
                word[cur] = s.charAt(i);
                dfs(digits, cur+1);
            }
        }
    }
```


