1. 根据数学中的**换底公式**获取到i和j的最大值，这里要注意的是两者中有为1的情况的话要单独处理
2. 双重循环i和j，得到其中的一个强整数，当已经超过bound时可以跳出内层循环节省时间
3. 保存的结果用set自动去重，最后转换为list
```
class Solution {
    public List<Integer> powerfulIntegers(int x, int y, int bound) {
        int iMax = x == 1 ? 0 : (int)(Math.log(bound-1) / Math.log(x));
        int jMax = y == 1 ? 0 : (int)(Math.log(bound-1) / Math.log(y));
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i <= iMax; i++) {
            for (int j = 0; j <= jMax; j++) {
                if (Math.pow(x,i) + Math.pow(y,j) <= bound) {
                    set.add((int)(Math.pow(x,i) + Math.pow(y,j)));
                } else break;
            }
        }
        return new ArrayList<>(set);
    }
}
```
