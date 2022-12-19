### 解题思路
每次递归, 先把能打开的箱子都打开.
把initialBoxes中已经打开的箱子的糖果拿走.
把initialBoxes中已打开的箱子包含的其他箱子, 及initialBoxes中未打开的箱子再递归.
### 代码

```java
class Solution {
  public int maxCandies(int[] status, int[] candies, int[][] keys, int[][] containedBoxes, int[] initialBoxes) {
    List<Integer> nextBoxes = new ArrayList<>();
    for (int i = 0; i < initialBoxes.length; i++) {
      nextBoxes.add(initialBoxes[i]);
    }
    return maxCandies(status, candies, keys, containedBoxes, nextBoxes);
  }

  public int maxCandies(int[] status, int[] candies, int[][] keys, int[][] containedBoxes, List<Integer> initialBoxes) {
    int count = 0;
    // 从拥有的箱子中拿出钥匙开箱子
    for (int b : initialBoxes) {
      if (status[b] == 1) {
        for (int key : keys[b]) {
          status[key] = 1;
        }
      }
    }

    boolean has = false; // 记录是否有拿走糖果.
    List<Integer> nextBoxes = new ArrayList<>();
    for (int b : initialBoxes) {
      if (status[b] == 1) {
        has = true;
        // 把当前箱子包含的箱子留到下个循环.
        for (int cb : containedBoxes[b]) {
          nextBoxes.add(cb);
        }
		// 拿走糖果
        count += candies[b];
      } else {
        // 当前箱子未打开也留到下个循环.
        nextBoxes.add(b);
      }
    }

    // 如果本次没有糖果可拿, 因为能打开的箱子都打开了, 则不用再取剩余的箱子了.
    if (has) {
      count += maxCandies(status, candies, keys, containedBoxes, nextBoxes);
    }
    return count;
  }
}
```