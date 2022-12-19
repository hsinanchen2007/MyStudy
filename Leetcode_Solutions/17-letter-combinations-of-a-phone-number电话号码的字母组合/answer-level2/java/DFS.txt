执行用时 :0 ms, 在所有 java 提交中击败了100.00% 的用户
内存消耗 :35.7 MB, 在所有 java 提交中击败了76.37%的用户
```
class Solution {
    String[] strings = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    List<String> list = new ArrayList();
    public List<String> letterCombinations(String digits) {
        if(digits == null || digits.length() < 1)
            return list;
        char[] ch = digits.toCharArray();
        getResult(ch, "", 0, ch.length);
        return list;
    }
    public void getResult(char[] ch, String str, int start, int length){
        if(start == length){
            list.add(str);
            return;
        }
        int index = ch[start]-'0'-2;
        char[] temp = strings[index].toCharArray();
        for(int j = 0; j < temp.length; j++){
            getResult(ch, str+""+temp[j], start+1, length);
        }
    }
}
```
