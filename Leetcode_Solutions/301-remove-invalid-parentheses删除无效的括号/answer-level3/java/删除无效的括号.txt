### 解题思路
1. 主要思路是找出无效的左右括号的数量，然后遍历字符串依次删除多余的括号，每删除一次，就进行递归判断，类似深度优先搜索，直至无效的左右括号数量为0.否则回溯。
2. 递归函数的参数有一个start，因为之前的状态已经搜索过，避免重复搜索造成重复结果。

### 代码

```java
class Solution {
    private List<String> res;
    public List<String> removeInvalidParentheses(String s) {
        res = new ArrayList<>();
        int left = 0, right = 0;
        for(char c : s.toCharArray()){
            if(c == '(') left++;
            else if(c == ')'){
                if(left > 0) left--;
                else right++;
            }
        }
        dfs(s, 0, left, right);
        return res;
    }

    private void dfs(String s, int start, int left, int right){
        if(left == 0 && right == 0){
            if(check(s)) res.add(s);
            return;
        }
        StringBuffer sb = new StringBuffer();
        for(int i = start; i < s.length(); i++){
            if(i > start && s.charAt(i) == s.charAt(i-1)) continue;
            else if(left > 0 && s.charAt(i) == '('){
                sb.setLength(0);
                sb.append(s.substring(0, i));
                sb.append(s.substring(i+1));
                dfs(sb.toString(), start, left-1, right);
            }
            else if(right > 0 && s.charAt(i) == ')'){
                sb.setLength(0);
                sb.append(s.substring(0, i));
                sb.append(s.substring(i+1));
                dfs(sb.toString(), start, left, right-1);
            }
        }
    }

    private boolean check(String s){
        int left = 0;
        for(char c : s.toCharArray()){
            if(c == '(') left++;
            else if(c == ')'){
                if(left == 0) return false;
                left--;
            }         
        }
        return left == 0;
    }
}
```