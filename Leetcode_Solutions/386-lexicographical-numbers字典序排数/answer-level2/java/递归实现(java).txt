# 递归实现
```
class Solution {
    public List<Integer> lexicalOrder(int n) {
        List<Integer> list = new ArrayList<>();
        for (int i = 1; i <= 9; i ++) {
            lexicalOrder(list, i, n);
        }
        return list;
    }

    private void lexicalOrder(List<Integer> list, int curVal, int maxVal) {
        if (curVal > maxVal) {
            return;
        }
        list.add(curVal);
        curVal *= 10;
        for (int i = 0; i <= 9; i ++) {
            lexicalOrder(list, curVal + i, maxVal);
        }
    }
}
```
# 十叉树的前序遍历

```
根 -> 左节点 -> 右节点
```

