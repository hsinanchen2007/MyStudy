## 草稿
![fullsizerender.jpg](https://pic.leetcode-cn.com/5dd2b760d1f8e98328da7735fb71c052ebba3f8e687d68fbf01d386c69e41de8-fullsizerender.jpg)
## 思路
就如草稿中打的那样，我觉得每一个灯点亮的时候，它都会影响“整行”，“整列”，“正对角线”，“反对角线”。

![2.jpg](https://pic.leetcode-cn.com/1e9d9c66e09f701cf69dde93a7deb1c4f055ca1fea6041037ef605906dc7bdf3-2.jpg)
如果两个灯在一行，我们显而易见可以得知这一行一定会被点亮。同时我们知道，如果我们熄灭其中一盏灯，这一行依旧充满光明！因为还有另一盏灯依然坚挺！只有当两盏灯同时熄灭，这一行才会重新回归黑暗。但是被熄灭的灯所处的列以及对角线波及到的区域，都会在它熄灭的同时，也陷入黑暗。

![3.jpg](https://pic.leetcode-cn.com/a9d4e65795b59ade17c2e31ac5daa793f461357a5a9f2ef5ef341a200ba41e32-3.jpg)
这让我们可以进行第一次抽象，看成每一盏灯的点亮都会对波及到的格子进行“计数+1”。而每一盏灯的熄灭都会对波及到的格子进行“计数-1”。

这样，如图，两盏同一行的灯，所处的行的计数就会变成2。这意味着，只有当两盏灯同时熄灭，才能让这一行的计数变成0（也就是变黑）。

但是问题来了，题目中给出的N的大小最大是10的九次方。显然，不可能开辟一个足够大的数组空间可供挥霍（时间也不允许）。

接下来，于是就如开头草稿中写的，我们可以设计四个记录器。之所以设计记录器是因为，每点亮一个灯，就必然会点亮“一行”，“一列”，“一个正对角线”，“一个反对角线”。我们不再需要去记录每一个格子的“光源亮度”。

我们查看一个格子的光源亮度，也只需要去看“这一行是否被点亮”，“这一列是否被点亮”，“这一个正对角线是否被点亮”...只要这些条件中，任一一个满足，就说明这个格子是被点亮的。

行记录器的索引和列记录器的索引是非常好确定的，可以直接等于所处格子的横纵坐标。

而正反对角线记录器的索引确定方式，我写在了草稿中。

至于最终记录器的实现方式，最开始想当然的使用了数组（草稿中也列出了数组的大小）...但忽略了题目N的给定范围，最终使用HashMap实现了记录器。

```
class Solution {
    //四个记录器
    HashMap<Integer, Integer> colRecorder;
    HashMap<Integer, Integer> rowRecorder;
    HashMap<Integer, Integer> positiveRecorder;
    HashMap<Integer, Integer> negetiveRecorder;

    //一个灯光记录器
    HashMap<Integer, Integer> lampsRecorder;

    //初始化方向向量
    private int[] dy = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    private int[] dx = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
    private int directionLen = 9;

    private int N;

    public int[] gridIllumination(int N, int[][] lamps, int[][] queries) {
        //...
    }

    private int getPositiveIndex(int y, int x) {
        return x + y;
    }

    private int getNegetiveIndex(int y, int x) {
        return y - x + N - 1;
    }
}
```