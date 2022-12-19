- 最大值 
- 第一个石头移到第二个石头的后面的第一个空位上  重复执行以上操作 直到所有石头连在一起
- 移动的位数 就等于第一个石头到最后一个石头之间的空位数
- 还有一种可能就是从右到左 倒数第一个石头移到倒数第二个石头的前面的第一个空位上
- 最小值
- 一个长度为n的滑动窗口 用来表示石头的最终位置
- 为了尽可能少的移动 则滑动窗口在初始时应该尽可能多的放石头
- 因此第一个石头必须在滑动窗口的第一个位置
- 然后找到滑动窗口的空位 就知道了移动的步数
- 有一种特殊情况  就是在滑动窗口初始化时出现连续n-1个石头 但不是连续n个石头时
- 不需要计算  因为这个滑动窗口无法被填满 最优解不会是以这个石头为起点
- 如 1235 最优解肯定不会以1开头 
- 如 1345 最优解肯定不会以3开头
```
var numMovesStonesII = function (stones) {
  stones.sort((a, b) => a - b);
  let len = stones.length - 1;
  let min = len;
  for (let i = 0; i <= len; ++i) {
    let tempI = i + 1;
    while (tempI <= len && stones[tempI] - stones[i] <= len) {
      ++tempI
    }
    if (tempI - 1 - i === len - 1 && stones[tempI - 1] - stones[i] === len - 1) {
      continue;
    }
    min = Math.min(min, len + 1 + i - tempI);
    if (tempI === len) {
      break;
    }
  }
  return [min, Math.max(stones[len] - stones[1], stones[len - 1] - stones[0]) + 1 - len]
};
```
