递归可能会更好的体现本游戏的过程。思维过程会比较直接。要点如下：
1 每一次递归，就代表游戏中的一轮。这次可能是轮到 ALEX 了（alex = ture），也可能是轮到 LEE了(alex = false)。
2 每一轮之前，ALEX的石子数 减去 LEE的石子数， 这个差值是确定的，这个值传入本轮（val）。
3 游戏者可以从左边（i）取走石子，也可以从右边（j）取走石子。
4 当石子只剩一堆，最后一个人取完就结束了，如果 差值 大于零的，ALEX 就赢了（返回 true）, 否则就输（返回 false）
5 当然，可能会有很多种取法，但只要其中有一种取法能让 ALEX 赢, 结果就是 TURE。
6 最后就是递归有可能会超时

```
bool stone(int* piles, int i, int j, int val, bool alex) {
    int vl, vr;
    //terminater
    if (i == j) {
        return (((alex) ? (val + piles[i]):(val - piles[i])) > 0);
    }

    //process
    vl = (alex) ? (val + piles[i]):(val - piles[i]);
    vr = (alex) ? (val + piles[j]):(val - piles[j]);

    //recursion
    return stone(piles, i+1, j, vl, !alex) || stone(piles, i, j+1, vr, !alex);
}

bool stoneGame(int* piles, int pilesSize){
    return stone(piles, 0, pilesSize-1, 0, true);
}

```
