```
class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int X) {
        int finalMax = 0;
        int currentMax = 0;
        // 计算不使用技能时的结果
        for (int i=0; i<customers.length; i++) {
            if (grumpy[i] == 0) {
                currentMax += customers[i];
            }
        }
        // 计算使用滑动窗口计算技能带来的最大提升
        int increase = 0;
        for (int i=0; i<X; i++) {
            if (grumpy[i] == 1) {
                increase += customers[i];
            }
        }
        int increaseMax = increase;
        for (int i=X; i<customers.length; i++) {
            // 加上当前记录
            if (grumpy[i] == 1) {
                increase += customers[i];
            }
            // 减去之前记录
            if (grumpy[i-X] == 1) {
                increase -= customers[i-X];
            }
            // 保留最大值
            if (increaseMax < increase) {
                increaseMax = increase;
            }
        }
        // 累加获得最大值
        finalMax = currentMax + increaseMax;
        return finalMax;
    }
}
```
