### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    List<String> res = new LinkedList<>();
    public List<String> generateParenthesis(int n) {
        dfs(n, n, "");
        return res;
    }

    public void dfs(int left, int right, String curr){
        if(left == 0 && right == 0){
            res.add(curr);
            return;
        }
        if(left > 0){
            dfs(left - 1, right, curr + "(");
        }

        if(right > left){
            dfs(left, right - 1, curr + ")");
        }
    }
}
```