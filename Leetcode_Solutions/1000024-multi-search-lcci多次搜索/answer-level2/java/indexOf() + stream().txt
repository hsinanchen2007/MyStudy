# 代码
```java
class Solution {
    private int[][] res;
    private String global_big;

    public int[][] multiSearch(String big, String[] smalls) {
        int len = smalls.length;
        res = new int[len][];
        global_big = big;
        for (int i = 0; i < len; ++i)
            addToRes(i, smalls[i]);
        return res;
    }

    private void addToRes(int position, String str) {
        if (str.equals("")) {
            res[position] = new int[0];
            return;
        }
        LinkedList<Integer> list = new LinkedList<>();
        int idx = 0;
        while ((idx = global_big.indexOf(str, idx) + 1) != 0)
            list.addLast(idx - 1);
        res[position] = list.stream().mapToInt(Integer::intValue).toArray();
    }
}
```
