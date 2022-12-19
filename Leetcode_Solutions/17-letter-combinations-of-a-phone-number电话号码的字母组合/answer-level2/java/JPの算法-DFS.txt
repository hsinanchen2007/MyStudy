```
class Solution {
    Map<Character, String> phone = new HashMap<Character, String>() {{
        put('2', "abc");
        put('3', "def");
        put('4', "ghi");
        put('5', "jkl");
        put('6', "mno");
        put('7', "pqrs");
        put('8', "tuv");
        put('9', "wxyz");
    }};

    private List<String> list = new ArrayList<>();
    public List<String> letterCombinations(String digits) {
        if(digits.length()==0)
            return list;
        dfs(digits,0,"");
        return list;
    }

    public void dfs(String digits,int index,String ans){
        if(index == digits.length()){
            list.add(ans);
            return ;
        }

        Character c = digits.charAt(index);
        String letter = phone.get(c);
        for(int i=0;i<letter.length();i++){
            dfs(digits,index+1,ans+letter.charAt(i));
        }

    }
}
```
