```
public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> res = new ArrayList<>(numRows);
        for (int i = 1; i <= numRows; i++) {
            List<Integer> now = new ArrayList<>(i);
            for (int j = 0; j < i; j++) {
                if (j == 0 || j == i - 1) now.add(1);
                else now.add(res.get(i - 2).get(j - 1) + res.get(i - 2).get(j));
            }
            res.add(now);
        }
        return res;
    }
```
