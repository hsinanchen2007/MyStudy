```
class Solution {
    String[] strs = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};//后面是减0，所以最前面两个“”
    public List<String> letterCombinations(String digits) {
        List<String> res = new ArrayList<>();
        if(digits == null || digits.length() == 0)
            return res;
        dfs(digits, new StringBuilder(), res);
        return res;
    }
    private void dfs(String digits, StringBuilder cur, List<String> res){
        if(digits.length() == cur.length()){
            res.add(cur.toString()); //类型转换，加到最终结果
            return;
        }
        int curdigit = digits.charAt(cur.length())-'0';//目前处理到输入数字字符串中的第curdigit个
        String curstr = strs[curdigit];
        for(char c : curstr.toCharArray()){//注意类型转换
            cur.append(c);//注意函数，和add区别开
            dfs(digits,cur,res);
            cur.deleteCharAt(cur.length()-1);//删除最后一个
        }
    }
}
```
