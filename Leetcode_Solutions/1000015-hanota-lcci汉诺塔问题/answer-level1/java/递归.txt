### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    /**
     * 递归
     * 1. 当A只有一个时，直接移动到C
     * 2. 要移动第n个盘子，需要先移动第n-1个盘子
     * 2. 当A有 n 个时，需要将 第n-1个盘子（也就是最小的盘子）借助C移动到B
     * 3. 然后将A上的剩余的大盘子，移动到c
     * 4. 再讲B上的第n-1个盘子，借助A移动到C
     */
    public void hanota(List<Integer> A, List<Integer> B, List<Integer> C) {
        hanota(A.size(), A, B, C);
    }

    /**
     *
     * @param n 移动第几个盘子
     * @param source 要移动的柱子
     * @param temp 借助的柱子
     * @param target 目标柱子
     */
    private void hanota(int n, List<Integer> source, List<Integer> temp, List<Integer> target) {
        if (n == 1) {
            target.add(source.remove(source.size() - 1));// 将后一个大盘子移动到c
            return;
        }

        // 借助C将n-1个盘子移动到B
        hanota(n - 1, source, target, temp);
        // 将第n盘子（最大的盘子）移动到C
        target.add(source.remove(source.size() - 1));
        // 然后B借助a将盘子移动到c
        hanota(n - 1, temp, source, target);
    }
}
```