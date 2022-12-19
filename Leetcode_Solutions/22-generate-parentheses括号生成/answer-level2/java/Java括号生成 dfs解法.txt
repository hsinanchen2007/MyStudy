### 解题思路
需要考虑的问题：
1.何时添加结果?
首先，若保证括号有效，则最后一次添加的括号一定是右括号————')',那么当最后一个')'添加后
将字符串temp加入List里。
2.何时递归?递归的条件有什么限制?
一共有两种情况：加左括号'(' 或者 加右括号')'
那么什么时候能加左括号呢?当然是左括号的个数<n的时候;
什么时候可以加右括号?换个想法，什么时候不能加右括号：如果当前左右括号个数相等，再加入右括号
会导致当前字符串表示的括号无效，比如"(())"再加入")"

### 代码

```java
class Solution {
    List<String> res = new ArrayList<>() ;
    public List<String> generateParenthesis(int n) {
        if(n == 0) return res ;
        dfs(1,0,n,"(") ;
        return res ;
    }
    public void dfs(int left,int right,int n,String temp){
        if(right == n){
            res.add(new String(temp)) ;
            return ;
        }else{
            if(left < n){
                dfs(left+1,right,n,temp+"(") ;
            }
            if(right < left){
                dfs(left,right+1,n,temp+")") ;
            }
        }
    }
}
```