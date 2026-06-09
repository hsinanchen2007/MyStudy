
![image.png](https://pic.leetcode-cn.com/be11aecafb819c0efae3b2070be2093468c0729fd9e7d8fe8be74a010b115620-image.png)

整了三种方法花式解决这个问题：迭代（bfs）、递归、chan 通道 & 并发

方法一：迭代（bfs）（0ms，3.1MB）

传统方法，用 bfs 生成遍历顺序，开两个队列分别存放这两种顺序，然后取队首元素进行对比，如果始终一致，表示是对称二叉树。
```
func isSymmetric(root *TreeNode) bool { // 迭代方法，bfs
    lq := []*TreeNode{}       // 从左向右遍历顺序的队列
    rq := []*TreeNode{}       // 从右向左遍历顺序的队列
    lq = append(lq, root)     // 加入初始节点
    rq = append(rq, root)
    for len(lq)!=0 && len(rq)!=0 {   // bfs
        lcur,rcur := lq[0], rq[0]    // 不同遍历顺序的队列，队首出队
        lq, rq = lq[1:], rq[1:]      // 删除队首元素
        if lcur==nil && rcur==nil {  // 空节点，不添加节点
            continue
        } else if lcur!=nil && rcur!=nil && lcur.Val == rcur.Val {    // 比较两种遍历顺序的出队节点，如果相同，继续搜索
            lq = append(lq, lcur.Left, lcur.Right)
            rq = append(rq, rcur.Right, rcur.Left)
        } else {                     // 如果不同，证明不是镜像二叉树
            return false
        }
    }
    if len(lq)==0 && len(rq)==0 {    
        return true
    } else {
        return false
    }
}
```

方法二：递归（0ms，3.1MB）

果然递归的代码最简洁 = =
```
func isSymmetricGo(t1 *TreeNode, t2 *TreeNode) bool {
    if t1==nil && t2==nil {
        return true
    } else if t1==nil || t2==nil {
        return false
    }
    return t1.Val == t2.Val && isSymmetricGo(t1.Left, t2.Right) && isSymmetricGo(t1.Right, t2.Left)
}

func isSymmetric(root *TreeNode) bool {
    return isSymmetricGo(root, root)
}
```

方法三：chan 通道 & 并发（4ms，3.7MB）

思路是开两个协程分别生产两种递归顺序，然后主线程依次接收，并对比每次产生的顺序是否一致，如果始终一致，表示是对称二叉树。

这个方法思路更加直观，但是速度一般，空间占用高，属于灵机一动的使用 chan 练手作品，大家看看就好。
```
func getNodeCount(cur *TreeNode) int {
    if cur == nil {
        return 1
    }
    return getNodeCount(cur.Left) + getNodeCount(cur.Right) + 1
}

func LeftGen(lchan chan int, cur *TreeNode) {
    if cur == nil {
        lchan <- -1
        return 
    }
    lchan <- cur.Val    // 加入左遍历顺序通道
    LeftGen(lchan, cur.Left)
    LeftGen(lchan, cur.Right)
}

func RightGen(rchan chan int, cur *TreeNode) {
    if cur == nil {
        rchan <- -1
        return 
    }
    rchan <- cur.Val    // 加入左遍历顺序通道
    RightGen(rchan, cur.Right)
    RightGen(rchan, cur.Left)
}

func isSymmetric(root *TreeNode) bool { // 使用通道 chan 构造迭代器，判断每次结果是否一样
    nodeCount := getNodeCount(root)           // 总节点数（加上nil节点）
    lchan := make(chan int)
    rchan := make(chan int)
    go LeftGen(lchan, root)     // 开协程生成遍历顺序
    go RightGen(rchan, root)
    for nodeCount>0 {
        lcur := <- lchan        // 从通道中分别取出遍历顺序
        rcur := <- rchan
        if lcur != rcur {       // 判断遍历顺序是否相同
            return false
        }
        nodeCount--
    }
    defer close(lchan)          // 使用 defer 关键字在函数 return 之后关闭通道
    defer close(rchan)
    return true
}
```
