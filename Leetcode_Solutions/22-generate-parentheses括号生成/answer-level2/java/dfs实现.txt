### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> list = new ArrayList<>();
        if(n == 0){
            return list;
        }
        dfs("", n, n, list);
        return list;
    }

    private void dfs(String s, int left, int right, List<String> list){
        if(left > right){
            return;
        }
        if(left == 0 && right == 0){
            list.add(s);
        }
        if(left > 0){
            dfs(s + "(", left - 1, right, list);
        }
        if(right > 0){
            dfs(s + ")", left, right - 1, list);
        }
    }
}
```