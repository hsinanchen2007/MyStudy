```java
public List<String> generateParenthesis(int n) {
        List<String> res=new ArrayList<>();
        dfs(res, new StringBuilder(), 0, n);
        return res;
    }
    void dfs(List<String> list, StringBuilder sb, int left, int n){
        if(left<0 || left>n) return;
        if(left==0 && n==0) list.add(sb.toString());
        dfs(list, sb.append('('), left+1, n);
        sb.deleteCharAt(sb.length()-1);
        dfs(list, sb.append(')'), left-1, n-1);//当添加一个右括号，相当于抵消一个左括号
        sb.deleteCharAt(sb.length()-1);
    }
```
