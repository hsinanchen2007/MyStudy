### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    List<List<Integer>> ans;
    boolean[] col, dia1, dia2;
    public int totalNQueens(int n) {
        ans = new ArrayList<>();
        col = new boolean[n];
        Arrays.fill(col, false);
        dia1 = new boolean[2 * n - 1];
        Arrays.fill(dia1, false);
        dia2 = new boolean[2 * n - 1];
        Arrays.fill(dia2, false);
        findQueue(n, 0, new LinkedList<>());
        return ans.size();

    }
    private void findQueue(int n, int index, LinkedList<Integer> list){
        if (index == n){
            ans.add(new LinkedList<>(list));
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!col[i] && !dia1[index + i] && !dia2[index - i + n - 1]){
                list.add(i);
                col[i] = true;
                dia1[index + i] = true;
                dia2[index - i + n - 1] = true;
                findQueue(n, index + 1, list);
                col[i] = false;
                dia1[index + i] = false;
                dia2[index - i + n - 1] = false;
                list.removeLast();
            }
        }
    }
}
```