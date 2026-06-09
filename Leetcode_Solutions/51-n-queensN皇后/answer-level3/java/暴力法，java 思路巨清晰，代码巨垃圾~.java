dorun 函数每层递归，i==n-1时添加答案，否则像下递归
dorun2 判断当前位置是否符合Q的条件

```
    public class SolveNQueens {
    private List<List<String>> ans;

    public List<List<String>> solveNQueens(int n) {
        ans = new ArrayList<>();
        dorun(new ArrayList<>(), new HashMap(), 0, n);
        return ans;
    }

    private void dorun(List<String> list, Map<Integer, Integer> map, int i, int n) {

        for (int j = 0; j < n; j++) {
            if (!map.containsValue(j) && dorun2(map, i, j, n)) {
                List<String> list2 = new ArrayList<>(list);
                HashMap map2 = new HashMap(map);
                StringBuffer s = new StringBuffer();
                for (int k = 0; k < n; k++) {
                    if (k == j) s.append('Q');
                    else s.append('.');
                }
                map2.put(i, j);
                list2.add(s.toString());
                if (i == n - 1) ans.add(list2);
                else dorun(list2, map2, i + 1, n);
            }
        }

    }

    private boolean dorun2(Map map, int i, int j, int n) {
        int i2 = i, j2 = j;
        while (i2 > 0 && j2 > 0)
            if (map.containsKey(--i2) && (int) map.get(i2) == --j2) return false;
        i2 = i;
        j2 = j;
        while (i2 > 0 && j2 < n - 1)
            if (map.containsKey(--i2) && (int) map.get(i2) == ++j2) return false;
        i2 = i;
        j2 = j;
        while (i2 < n - 1 && j2 < n - 1)
            if (map.containsKey(++i2) && (int) map.get(i2) == ++j2) return false;
        i2 = i;
        j2 = j;
        while (i2 < n - 1 && j2 > 0)
            if (map.containsKey(++i2) && (int) map.get(i2) == --j2) return false;

        return true;
    }
  }
```
