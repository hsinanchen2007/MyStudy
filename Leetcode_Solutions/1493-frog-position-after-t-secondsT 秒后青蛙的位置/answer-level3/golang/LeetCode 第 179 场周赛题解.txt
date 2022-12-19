## 1374. 生成每种字符都是奇数个的字符串
**题目类型：构造** [题目链接](https://leetcode-cn.com/problems/generate-a-string-with-characters-that-have-odd-counts/)
若 $n$ 为奇数，则直接拼凑 $n$ 个相同的字符即可。
若 $n$ 为偶数，则用 $1$ 个 $A$ 和 $n-1$ 个 $B$ 拼凑即可。

```go
func generateTheString(n int) string {
    var str string
    if n % 2 == 1 {
        for i := 0; i < n; i++ {
            str += "a";
        }
    } else {
        str = "a"
        for i := 1; i < n; i++ {
            str += "b";
        }
    }
    return str;
}
```
## 1375. 灯泡开关 III
**题目类型：思维题** [题目链接](https://leetcode-cn.com/problems/bulb-switcher-iii/)
当第 $1$ 盏灯点亮时，其必为蓝色。当第 $i$ 盏灯为蓝色时，必有前 $i$ 盏灯都是亮的，此时点亮第 $i+1$ 灯，则第 $i+1$ 盏灯也为蓝色。
综上，若在 $t$ 时刻，点亮的 $t$ 盏灯均为蓝色，则这 $t$ 盏灯的序号必然是连续的且从 $1$ 开始。
所以当 $t$ 满足 $max(light[1...t]) == t$ 时，点亮的 $t$ 盏灯全为蓝色。
```go
func numTimesAllBlue(light []int) int {
    var maxLight int
    var anw int
    for k, v := range light {
        if v > maxLight {
            maxLight = v
        }
        if maxLight == k+1 {
            anw += 1
        }
    }
    return anw
}
```
## 1376. 通知所有员工所需的时间
**题目类型：图论** [题目链接](https://leetcode-cn.com/problems/time-needed-to-inform-all-employees/)
首先建立模型，$headID$ 为根节点。每个 $id$ 的 $下属员工id$ 为其子节点.两点相连的边的权值为对应的 $informTime$ 值。
则员工 $i$ 收到消息所需时间为节点 $i$ 和根节点的最短路径的权值累加和。则最晚收到消息的员工所需时间即为答案。
```go
func numOfMinutes(n int, headID int, manager []int, informTime []int) int {
    value := make([]int, n)
    for i := 0; i < n; i++ {
        value[i] = -1
    }
    var dfs func(cur int) int
    dfs = func(cur int) int {
        if value[cur] != -1 {
            return value[cur]
        }
        pre := manager[cur]
        if pre == -1 {
            value[cur] = 0
        } else {
            value[cur] = informTime[pre] + dfs(pre)
        }
        return value[cur]
    }
    var res int
    for i := 0; i < n; i++ {
        tmp := dfs(i)
        if tmp > res {
            res = tmp
        }
    }
    return res
}
```
## 1377. T 秒后青蛙的位置
**题目类型：图论** [题目链接](https://leetcode-cn.com/problems/frog-position-after-t-seconds/)
概率计算的公式容易推，需要分类讨论。代码写起来有点麻烦。
设 $depth_i$ 为节点 $i$ 的深度。
设 $count_u$ 为节点 $i$ 子节点的个数。
当节点 $i$ 不是叶子节点时有
$$
rate = \left\{ \begin{array}{c}
0, t-1 ≠ depth_i \\ 
\prod_{j∈path_[root, j)}\frac{1}{count_j}, t-1 = depth_i \\     
\end{array}\right. 
$$
当节点 $i$ 是叶子节点时有
$$
rate = \left\{ \begin{array}{c}
0, t-1 < depth_i \\ 
\prod_{j∈path_{[root,i)}}\frac{1}{count_j}, t-1 >= depth_i \\     
\end{array}\right. 
$$
```go
func frogPosition(n int, edges [][]int, t int, target int) float64 {
    vec := make([][]int, n)
    depth := make([]int, n)
    rate := make([]float64, n)

    for _, edge := range edges {
        u, v := edge[0] - 1, edge[1] - 1
        vec[u] = append(vec[u], v)
        vec[v] = append(vec[v], u)
    }

    var dfs func(root, pre int, r float64, d int)
    dfs = func(root, pre int, r float64, d int) {
        rate[root] = r
        depth[root] = d
        for _, p := range vec[root] {
            if p != pre {
                if pre == -1 {
                    dfs(p, root, r/float64(len(vec[root])), d+1)
                } else {
                    dfs(p, root, r/float64(len(vec[root])-1), d+1)
                }
            }
        }
    } 
    
    dfs(0, -1, 1.0, 0)
    target -= 1
    vec[0] = append(vec[0], -1)
    if depth[target] == t || (t >= depth[target] && len(vec[target]) <= 1) {
        return rate[target]
    }
    return float64(0)
}
```

![扫描图片关注 HelloNebula 获取更多文章~](https://pic.leetcode-cn.com/de7a84a8e8aafcefb447b1abed8df53ec974b56231d2a137ff5e2fc5684f6d66.png)
**扫描图片关注 HelloNebula 获取更多文章~**