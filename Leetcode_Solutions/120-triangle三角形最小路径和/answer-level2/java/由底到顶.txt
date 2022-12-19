```
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int height = triangle.size();
        Map<Integer, Integer> map = new HashMap<>();

        for (int i = height - 1; i >= 0; i --) { // 层
            List<Integer> levelList = triangle.get(i);

            for (int j = 0; j < levelList.size(); j ++) {
                int x = map.get(j) == null ? 0 : map.get(j);
                int y = map.get(j + 1) == null ? 0 : map.get(j + 1);
                int minNum = levelList.get(j) + Math.min(x, y);
                map.put(j, minNum);
            }
        }
        return map.get(0);
    }
}
```
