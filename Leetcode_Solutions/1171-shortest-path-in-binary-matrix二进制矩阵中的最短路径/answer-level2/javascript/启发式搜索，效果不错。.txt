看题解没有找到启发式搜索的答案，就自己写了一个简陋版本的，还没有AC，至于为什么效果好你看完就明白了。先上一个测试用例的图：
![Snipaste_2020-03-18_17-04-13.png](https://pic.leetcode-cn.com/b84ce92301dc2e795240cb18a5f8fd3bfc75a5e6a70dcd4f028d4315109ba5c9-Snipaste_2020-03-18_17-04-13.png)
图中的红色线段为实际的遍历，是要比普通的BFS效果要好很多。

## 思路
普通的BFS就不赘述了，而启发式搜索就是对BFS的队列做了些手脚，就是我们用一个值，去衡量当前猜测的节点是在最近的路径上的可能性。
对于BFS而言，队列中每个元素只含有横纵坐标，这里因为我们不按照层次，而按照我们自己做的衡量可能性的值，所以我们对于每个点，需要有四个值：
+ 横坐标
+ 纵坐标
+ 权值
+ 深度
其中深度指的就是层数了。
还有对于A*算法概念可以参考下面的连接，这也是我们选择估算函数的依据。
[https://blog.csdn.net/zgwangbo/article/details/52078338]()
对于这道题来说，我选的估算的函数（我确实不清楚这个函数应该叫什么，应该是有专一名字）就是
```
let caculatef = (x, y, d) => {
    return Math.max(d-x,d-y)
}
```
通过最大差值估算，这个值一定是小于实际的步数，开始我用的是曼哈顿距离，但是有些问题就是相等的时候，步数如果差1的话对结果有影响，而且曼哈顿距离，可能大于实际用的步数，因为这个题可以斜着走233

然后先贴我的代码看一哈
```
var shortestPathBinaryMatrix = function (grid) {
    let caculatef = (x, y, d) => {
        return Math.max(d-x,d-y)
    }
    //使每次插入最后面的值，找到它对应的权值位置
    let resetQueue = _ => {
        let len = queue.length
        if (len < 2) return
        let item = queue[queue.length - 1]
        for (let i = 0; i < len - 1; i++) {
            if (queue[i][2] > item[2]) {
                queue.splice(i, 0, item)
                queue.pop()
                break
            }
        }
    }
    let len = grid.length
    if (grid[0][0] == 1 || grid[len - 1][len - 1] == 1) return -1
    if (len == 1) return 1
    let dis = 2
    //这里的值随便赋值都可以，因为第一个估值没意义。
    let queue = [
        [0, 0, 0, dis]
    ]
    grid[0][0] = 1
    while (queue.length) {
        let item = queue.shift()
        for (let i of [
                [item[0] - 1, item[1]],
                [item[0], item[1] - 1],
                [item[0] + 1, item[1]],
                [item[0], item[1] + 1],
                [item[0] - 1, item[1] - 1],
                [item[0] - 1, item[1] + 1],
                [item[0] + 1, item[1] + 1],
                [item[0] + 1, item[1] - 1]
            ]) {
            // 验证合法性
            if (i[0] >= 0 && i[0] < len && i[1] >= 0 && i[1] < len && grid[i[0]][i[1]] != 1) {
                // 找到对的
                if (i[0] == len - 1 && i[1] == len - 1) {
                    return item[3]
                }
                // 没找到就入队列
                // item[3]就是层数，权值是：层数+估算函数的值
                i.push(caculatef(i[0], i[1], len - 1) + item[3])
                i.push(item[3] + 1)
                queue.push(i)
                resetQueue()
            }

        }
        //当前节点走过之后堵上
        grid[item[0]][item[1]] = 1

    }
    return -1
};
```
其中很重要的一步就是resetQueue，每次计算出节点之后要对队列重排序。
到这看代码应该可以看出问题，因为每次向前探索，都需要对数组重排，而且做插入操作，还要遍历数组，当然因为数组多数保持有序，往往不会遍历完，但是，数组插入的时间复杂度可是O（n）啊，应该这就是导致超时的原因。改成链表应该会好很多。
具体的代码不复杂，对部分代码也有注释。

其实A*应该说是基于BFS，如果我们的权值，设置为节点发现的顺序，其实就是BFS。

此外，除了单方向的启发式，各位也可以尝试双边启发式搜索，这样的效果应该会更好。
