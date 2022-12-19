利用特性
- 最后一个赋值的元素，一定最大——可模拟倒放
- 能出现的数组，无论怎么换位置，总能出现——排序不影响
```java
public boolean isPossible(int[] target) {
    Arrays.sort(target);
    int len = target.length;
    if (target[len - 1] == 1) return true; // 还原为全1
    if (target[len - 1] < len) return false; // 剪枝

    int otherSum = 0; // 前面的总和
    for (int i = 0; i < len - 1; i++) {
        otherSum += target[i];
        if (target[len - 1] < otherSum) return false; // 剪枝，已超过最后一个
    }
    if ((target[len - 1] -= otherSum) <= 0) return false; // 剪枝，逐步还原
    return isPossible(target);
}
```

### 以下解法不行！为保留痕迹及思考过程，以下保留
- 测试用例未完善
- 如 `[1,1,1,2,5]` 任意尾部能通过 `target[len - 1] == len` 的都为 `true`
- 感谢 [@scoon](https://leetcode-cn.com/u/scoon/) 提醒

```java
public boolean isPossible(int[] target) {
    Arrays.sort(target);
    int len = target.length;
    if (target[len - 1] == len) return true;
    if (target[len - 1] < len) return false;

    int otherSum = 0; // 前面的总和
    for (int i = 0; i < len - 1; i++) {
        otherSum += target[i];
        if (target[len - 1] < otherSum) return false; // 已超过最后一个
    }
    target[len - 1] -= otherSum; // 想象成倒放电影，看看都发生了什么：最后一个赋值的一定最大
    return isPossible(target);
}
```
