```
class Solution {
    public int maxDistance(List<List<Integer>> arrays) {
        //获取每个数组的最大、最小值，再比较获取最大距离
        int max = -1;
        for (int i = 0; i < arrays.size(); i++) {
            for (int j = i + 1; j < arrays.size(); j++) {
                int a = Math.abs(arrays.get(i).get(0) - arrays.get(j).get(arrays.get(j).size() - 1));
                int b = Math.abs(arrays.get(i).get(arrays.get(i).size() - 1) - arrays.get(j).get(0));
                if (Math.max(a, b) > max) {
                    max = Math.max(a, b);
                }
            }
        }
        return max;
    }
}
```
