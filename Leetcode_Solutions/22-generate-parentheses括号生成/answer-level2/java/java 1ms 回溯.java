left:需求'('的数量，每次添加一个'('都要多需求一个')'
right:需求')'的数量
```java
class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<>();
        GP(res, new StringBuilder(), n, 0);
        return res;
    }

    private void GP(List<String> res, StringBuilder path, int left, int right) {
        if (left == 0 && right == 0) {
            res.add(path.toString());
            return;
        }
        if (left > 0) {
            path.append('(');
            GP(res, path, left - 1, right + 1);
            path.deleteCharAt(path.length() - 1);
        }
        if (right > 0) {
            path.append(')');
            GP(res, path, left, right - 1);
            path.deleteCharAt(path.length() - 1);
        }
    }
}
```
