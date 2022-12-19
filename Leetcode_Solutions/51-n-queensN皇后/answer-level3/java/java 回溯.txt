### 解题思路
1. 套用回溯的魔板代码
2. 按行处理，用 route 保存已经放置皇后的行
3. 放置下一行的时候需要判断水平和竖直方向是否已经放置，需要遍历已经放置的数组，处理斜线行，斜线的处理可以用如下方式判断
```
int diff = Math.abs(current - j);
(i == (posQ - diff)) || (i == (posQ + diff))
```
i 表示当前行中预放置的列号，j表示对已经放置的行的遍历，current 表示当前需要放置的行，
则 diff 标志当前行和已经放置的行的查，用 posQ 加、减 diff 可以得到斜线坐标 (current, posQ - diff) 和 (current, postQ + diff) 

### 代码

```java
class Solution {
     public List<List<String>> solveNQueens(int n) {
        List<List<String>> ans = new ArrayList<>();
        ArrayList<String> route = new ArrayList<>();
        backTrace(ans, route, n);
        return ans;
    }

    public String generateLine(int pos, int n) {
        char[] line = new char[n];
        Arrays.fill(line, '.');
        line[pos] = 'Q';
        return new String(line);
    }

    public boolean checkCanPlace(List<String> route, int i) {
        int current = route.size();
        for (int j = 0; j < route.size(); j++) {
            int posQ = route.get(j).indexOf('Q');
            if (i == posQ) return false; // 行列判断
            int diff = Math.abs(current - j);
            if ((i == (posQ - diff)) || (i == (posQ + diff))) return false; // 斜线判断
        }

        return true;
    }

    public void backTrace(List<List<String>> ans, List<String> route, int n) {
        if (route.size() == n) {
            ans.add(new ArrayList<>(route));
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!checkCanPlace(route, i)) continue;
            route.add(generateLine(i, n));
            backTrace(ans, route, n);
            route.remove(route.size() - 1);
        }
    }
}
```