### 解题思路
深度优先搜索DFS，注意搜索的条件：
1. 如果左括号有剩余，可以放一个左括号。
2. 如果右括号剩余数大于左括号，才可以放一个右括号。
终止条件：左右括号均无剩余

### 代码

```java
class Solution {
    public List<String> generateParenthesis(int n) {

        List<String> ans = new ArrayList<>();
        dfs(ans,n,n,"");
        return ans;

    }
    public void dfs(List<String> ans,int left,int right,String s){

        if(left == 0 && right == 0){//终止条件：左右括号均无剩余
            ans.add(s);
            return;
        }
        if(left > 0){//左括号有剩余
            dfs(ans,left-1,right,s+"(");
        }
        if(left < right){//右括号剩余数大于左括号
            dfs(ans,left,right-1,s+")");
        }
    }
}
```