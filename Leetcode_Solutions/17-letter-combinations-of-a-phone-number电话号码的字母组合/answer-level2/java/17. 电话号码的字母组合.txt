/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/10/17
 *
 * 解题思路: 算法复杂度 3^n 明显是二叉树的变形 三叉树
 *
 */
```
public class leetcode017 {
    List<String> list = new ArrayList<>();
    String[] letters = new String[]{"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    public List<String> letterCombinations(String digits) {
        if(digits.length() == 0){
            return list;
        }
        dfs(digits.toCharArray(),0,"");
        return list;
    }

    public void dfs(char[] root , int index, String s){
        if(index > root.length - 1){
            //叶子节点
            list.add(s);
            return;
        }
        dfs(root,index+1,s + letters[root[index]-'2'].charAt(0));
        dfs(root,index+1,s + letters[root[index]-'2'].charAt(1));
        dfs(root,index+1,s + letters[root[index]-'2'].charAt(2));
        if(root[index] == '7' || root[index] == '9'){
            dfs(root,index+1,s + letters[root[index]-'2'].charAt(3));
        }

    }

    public static void main(String[] args) {
        leetcode017 leetcode017 = new leetcode017();
        leetcode017.letterCombinations("2");
    }
}
```