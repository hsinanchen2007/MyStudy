### 解题思路

使用深度优先进行搜索, 结果存放在list中, 进行回溯

### 代码

```java
class Solution {
    List<String> result = new ArrayList<>();
    public List<String> generateParenthesis(int n) {
        backtrack(n, 0, 0, new LinkedList<Character>());
        return result;
    }
    void backtrack(int n, int i, int j, LinkedList<Character> list){
        if(i == n && j == n){
            StringBuilder sb = new StringBuilder();
            for(char ch: list){
                sb.append(ch+"");
            }
            result.add(sb.toString());
            return;
        }
        if(i < n){
            list.addLast('(');
            backtrack(n, i+1, j, list);
            list.removeLast();
        }
        if(j < i){
            list.addLast(')');
            backtrack(n, i, j+1, list);
            list.removeLast();
        }
    }
}
```