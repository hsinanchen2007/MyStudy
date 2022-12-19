```
 public List<String> letterCombinations(String digits) {
        List<String> ans = new ArrayList<>();
        StringBuilder builder = new StringBuilder();
        if (digits == null || digits.trim().equals("")) return ans;
        digits = digits.trim();
        char[][] c = {{'a','b','c'},{'d','e','f'},{'g','h','i'},
                      {'g','k','l'},{'m','n','o'},{'p','q','r','s'},
                      {'t','u','v'},{'w','x','y','z'}};
        helper(digits,c,0,builder,ans);
        return ans;
    }
    public void helper(String digits,char[][] c,int index,StringBuilder builder,List<String> ans){
        if (index >= digits.length()) {
            ans.add(builder.toString());
            return;
        }
        char digit = digits.charAt(index);
        int dig = digit-'2';
        for (int i = 0; i < c[dig].length; i++) {
            builder.append(c[dig][i]);
            helper(digits,c,index+1,builder,ans);
            builder.deleteCharAt(builder.length()-1);
        }
    }

```
