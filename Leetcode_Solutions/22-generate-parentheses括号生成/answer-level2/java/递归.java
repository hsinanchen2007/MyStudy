### 解题思路
括号都是成对的，左括号数等于右括号数，所以使用left代表剩余的左括号数，right代表右括号剩余的数
根据这两个值判断是否可以继续生成左括号还是又括号，最好是结合递归树来和。


### 代码

```java


class Solution {
    
    
    public List<String> generateParenthesis(int n) {
        
        List<String> result = new LinkedList<>();
        generateParenthesis("", n, n, result);
        return result;
    }   
    
    // str 当前递归得到的结果
    // left '('剩余的个数
    // right ')'剩余的个数
    // result 结果集
    private void generateParenthesis(String str, int left, int right, List<String> result) {
        
        // 剩余的左括号数 小于等于 右括号数 才是正确的状态
        // if (left > right) {
        //     return;
        // }
        
        if (left == 0 && right == 0) {
            result.add(str);
            return;
        }
        
        // 如果left大于0，可以继续生成左括号
        if (left > 0) {
            generateParenthesis(str + "(", left - 1, right, result);
        }
        
        // 如果left < right,可以继续生成右括号
        if (left < right) {
            generateParenthesis(str + ")", left, right-1, result);
        }
    }
    
    
}
```