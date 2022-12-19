### 思路
    1. 定义数字到字母的 映射
    2. 遍历给出的数字序列 
        1. 对于数字对应的字符串 进行for循环
        2. 将循环到的字符添加到 中间结果中
        3. 当递归深度到等于 **数字序列** 的长度 将中间结果 添加到结果集中
        4. 
    3. 
```
class Solution {
    //定义映射
     String a[] = {
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };

    private ArrayList<String> ans = new ArrayList<>();;
    public List<String> letterCombinations(String digits) {
        if(digits.isEmpty())
            return ans;
        dfs(0,new String(),digits);
        return ans;
    }
// 递归 不断生成中间结果 并添加到 结果集
    private void dfs(int depth,String midAns,String digits){
        if(depth==digits.length())
            ans.add(midAns);
        else
        {
            String nowNumString =getString( digits.charAt(depth));//当前正在处理的数字
             for(int i=0;i<nowNumString.length();i++){
                // sb.append(nowNumString.charAt(i));
                dfs(depth+1,midAns+nowNumString.charAt(i),digits);
            }
        }
           
    }
//返回 数字对应的 字符串
    private String getString(char b){
        return a[b-'0'-2];
    }
}
```
