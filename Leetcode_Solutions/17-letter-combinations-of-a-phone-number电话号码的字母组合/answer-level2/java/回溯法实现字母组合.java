```
class Solution {
     List<String> result = new ArrayList<>();
     Map<Character, String> map = new HashMap<Character, String>(){{
        put('2', "abc");
        put('3', "def");
        put('4', "ghi");
        put('5', "jkl");
        put('6', "mno");
        put('7', "pqrs");
        put('8', "tuv");
        put('9', "wxyz");
    }};
    public List<String> letterCombinations(String digits) {
         if(digits.length() != 0)
           backtrack(digits.toCharArray(),0,"");
        return result; 
    }
     private void backtrack(char[] chars, int i, String res) {
        if(i == chars.length){//i已经完成了依次数字遍历
            result.add(res);//将该分支结果加入list
            return;
        }
        String letters = map.get(chars[i]);//获取数字对应英文组合
        for (int j = 0; j < letters.length(); j++) {
            String letter = letters.substring(j,j+1);
            backtrack(chars,i+1,res + letter);
        }

    }
    
}
```
