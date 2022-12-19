```
 public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> result = new ArrayList<>();
        if (numRows == 0) return result;
        List<Integer> levelList = new ArrayList<>();
        levelList.add(1);
        result.add(levelList);
        levelList = new ArrayList<>();
        for (int i = 1; i < numRows; i++) {
            levelList.add(1);
            List<Integer> preList = result.get(i - 1);
            for (int j = 0; j < preList.size() - 1; j++) {
                int cur = preList.get(j) + preList.get(j + 1);
                levelList.add(cur);
            }
            levelList.add(1);
            result.add(levelList);
            levelList = new ArrayList<>();
        }
        return result;
    }
```
