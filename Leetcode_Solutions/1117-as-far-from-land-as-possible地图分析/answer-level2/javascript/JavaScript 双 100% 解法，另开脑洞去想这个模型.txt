
参考链接：[参考链接点这里](https://leetcode-cn.com/problems/as-far-from-land-as-possible/solution/zhen-liang-yan-sou-huan-neng-duo-yuan-kan-wan-miao/)

花了好长时间去理解题意，距离最近的陆地区域的最远距离，究竟是最远距离还是最近距离，后来看了链接中大佬画的 GIF 瞬间明白了，这道题或许换个模型更容易理解。

我脑补的模型：
- 背景：
    - 病毒在封闭人群中的传播（可能是最近瘟疫公司玩多了的缘故 orz）；
- 假设：
    - 将陆地看成是感染人员，每个感染人员 每天 都会感染周围的人，然后 第二天新感染的人员又会感染周围的人，问：你以上帝视角，站在人群中什么位置，才是最晚被感染的人（人类之光格陵兰）。
- 思路：
    - 第一天，算出被 0 号病人感染的人，剩下没感染的还有多少人
    - 第二天，算出被 第一天感染的人 感染的人，剩下没感染多少人
    - ……
    - 第 N 天，已经没有被感染的人了
    - 得到 N

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxDistance = function (grid) {
    let land = []; // 陆地源数组
    let level = 0; // 返回层级
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[i].length; j++) {
            if (grid[i][j] === 1) {
                land.push([i, j]);
            }
        }
    }
    let ocean = grid.length * grid.length - land.length; // 海洋的格数
    // 全是海洋或者陆地，返回 -1
    if (land.length === 0 || ocean === 0) {
        return -1;
    }
    while (ocean > 0) {
        level++;
        const temp = [];
        for (let i = 0; i < land.length; i++) {
            const [x, y] = [land[i][0], land[i][1]];
            // 判断 上下左右 相邻的点是否有海洋
            for (let j = 0; j < 4; j++) {
                // 边界条件校验
                if (
                    x + dx[j] < 0 ||
                    y + dy[j] < 0 ||
                    x + dx[j] > grid.length - 1 ||
                    y + dy[j] > grid[0].length - 1
                ) {
                    continue;
                }
                // 如果发现是海洋，则标记 2（这里其实只要是非 0，其他数都可以，只为了跟未知海洋作区分），防止被重复计算
                if (grid[x + dx[j]][y + dy[j]] === 0) {
                    grid[x + dx[j]][y + dy[j]] = 2;
                    temp.push([x + dx[j], y + dy[j]]);
                    // 每发现一个新海洋，剩下的海洋格数就减少 1
                    ocean--;
                }
            }
        }
        land = temp; // 一轮扩散结束后，新扩散将代替源陆地存入 land，开始新的一轮扩散
    }
    return level;
};
const dx = [1, -1, 0, 0];
const dy = [0, 0, 1, -1];
```
![](https://pic.leetcode-cn.com/069cec29a83cd04d22008abfbd962028ba05346a93de2b6e627f84fbd333c0e6.jpg)