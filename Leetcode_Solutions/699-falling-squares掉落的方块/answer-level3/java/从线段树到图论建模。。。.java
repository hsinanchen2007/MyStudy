### 解题

还是老样子，不管是先看题目描述还是先看题目标签，都可随意安排。

因为我是先选了线段树的标签，然后随机选一个题看看，这样子先看题目标签再看题目描述，没毛病！

想到线段树，自然会想到它的框架，先分治再合并。不过这道题，可不是先分支再合并这么简单了。

我们看完题目描述之后，假设输入示例是这样的 `{{5, 2}, {6, 1}, {4, 1}, {2, 3}}` ，按照线段树的框架，自然会变成下面这样的：

![分治](https://pic.leetcode-cn.com/b9e95622bb73bc427772bfee528fe6cf9f54975f624248d01bd9757b2a78c038.png)

我们得到的树底下的节点之后，怎么拆分是一个问题，怎么合并也是一个问题。

例如我们得到 {5，2}这个节点，可以设计成 {5，7，2}，分别是左边界、有边界和高度，不过我们设计的高度是向下的，如下面图：

![一个方块](https://pic.leetcode-cn.com/3924fa2db3a8f67f97655804844dec8098e6be43e4b897b40f14feaddef2840e.png)

通过左递归得到{5，2}这个节点，变换成{5，7，2}；通过右递归得到{6，1}这个节点，变换成{6，7，1}；接着进行合并，这个问题就来了，怎么合并也是一个问题。

或许我们可以设计成下面这样：

![方块表示](https://pic.leetcode-cn.com/172a1a10475875ad3857154c891a57f2acd03dc9f4abf5c03526edc0cf9c957f.png)

因为，题目要求掉落的方块是有顺序性的，不可能随机掉落哪个方块仍然答案是唯一的。所以我们按照了每个节点的左边界进行比较。

如果这个节点的左边界比根节点左边界小的话，那这个节点往根节点的左孩子递归；反之这个节点往根节点的右孩子递归；到下一个孩子节点也是这样比较和递归。

最后，我们得到了这样的一个图：

![假设合并成这样](https://pic.leetcode-cn.com/deaecb864b6b2c2ca6d3e0b3461664d56824c92df86316adc57dbefe13553dd2.png)



最关键的一点来了，接着上面的图，这两个子集合并应该怎样进行呢？

因为我们要保证方块掉落的顺序，右边子集的根节点要先和左边子集的根节点比较和递归，变成下面这样的：

![1582867054640](https://pic.leetcode-cn.com/d582a49990a20ad29be8d3a2a815913a74ba10e9ea4b83c633eed3d620c9d3c5.png)

而且从上面的图可以翻译成下面这样的：

![方块掉落](https://pic.leetcode-cn.com/c7d699a295ae3589c75e9c30a241646524716da662235061079288a51ec2301c.png)

这已经涉及到图论建模了，这图不管是进行深度遍历还是广度遍历总会找到目前区间的最高的高度。

但是这已经不符合线段树的优化了，我们知道线段树可以分治吧，分治的目的是降低时间复杂度。

你看，如果掉落的方块变成下面这样的，如果要找到区间【7，8】，就只能通过深度遍历或广度遍历才能找到这区间的最高高度为3。

![图论建模](https://pic.leetcode-cn.com/f3edb5576adbed67d62a20ef12512f1bc6cf1d560158fa6114f613c80bd7e67b.png)

如果我们把图论建模成下面这样的：

![换一个方式](https://pic.leetcode-cn.com/7937257b8959329009571df71497bc9af0b50c75720daa68bf6f073a6e138fa6.png)

再复杂点，就变成下面这样的，如果找到【3，5】，遍历的时候可以判断是否满足`r <= root.l`这个条件，如果满足，就没必要递归这个节点的右孩子了，因为5根本就不可能跑到5后面的坐标，所以我在这个地方进行了剪枝操作，待会看后面代码会有注释。

![图论建模](https://pic.leetcode-cn.com/161e244f9315b2b90eb3d51ee542fce1474d4c3b295ff897a72315b44efea608.png)

所以，我们本来想通过线段树的思路解决此题，到最后变成了图论建模。如果这道题是单纯的使用线段树，忘记了分治算法的优点的话，时间复杂度并没有O(log n)这样的，仍需要全部遍历才能找到这个区间的最高高度。

所以，在这道题上，我们先还是按顺序一个一个进行合并，如前面两个合并，第三个和前面合并，第四个和前面合并，依次类推。

既然线段树变成图论建模这地步了，我们就按着图论建模继续优化吧。

我们知道，我把这每一个节点定义成{左边界，右边界，高度}，每一次将节点放置的时候是不是先要获取这个区间的最高高度。

如果我们提前知道最有边界是多少，下一个方块的左边界要是比最有边界大的话，是不是直接获取0了，如下面这样的：

![降落](https://pic.leetcode-cn.com/f4c690e68c3ec6070b11b912551f43bc749aa9500e4bb8bcdea65f86c2f44c49.png)

所以，我们可以把方块定义成{l，r，h，maxR}，其中maxR表示目前最优边界。这样下一个节点降落的时候直接跟根节点的maxR比较，如果下一节点的左边界要大于等于maxR的话，可以直接获得这个区间的高度为 0。

最后，按照这个思路使用Java编写逻辑，执行用时也完胜100%的用户：

```
执行用时 : 6 ms , 在所有 Java 提交中击败了 100.00% 的用户
内存消耗 : 41.2 MB , 在所有 Java 提交中击败了 25.00% 的用户
```

而使用Go语言也一样。

```
执行用时 : 12 ms , 在所有 Go 提交中击败了 100.00% 的用户
内存消耗 : 5.6 MB , 在所有 Go 提交中击败了 100.00% 的用户
```

从执行结果上看，Go语言执行用时比Java耗时一点，但是内存消耗却比Java要少很多。

##### Java代码第一版本，未优化

```java
import java.util.*;

class Solution {
    // 描述方块以及高度
    private class Node {
        int l, r, h;
        Node left, right;

        public Node(int l, int r, int h) {
            this.l = l;
            this.r = r;
            this.h = h;
            this.left = null;
            this.right = null;
        }
    }

    // 线段树
    public List<Integer> fallingSquares(int[][] positions) {
        // 创建返回值
        List<Integer> res = new ArrayList<>();
        // 根节点，默认为零
        Node root = null;
        // 目前最高的高度
        int maxH = 0;

        for (int[] position : positions) {
            int l = position[0]; // 左横坐标
            int r = position[0] + position[1]; // 右横坐标
            int e = position[1]; // 边长
            int curH = query(root, l, r); // 目前区间的最高的高度
            root = insert(root, l, r, curH + e);
            maxH = Math.max(maxH, curH + e);
            res.add(maxH);
        }
        return res;
    }

    private Node insert(Node root, int l, int r, int h) {
        if (root == null) return new Node(l, r, h);
        if (l <= root.l)
            root.left = insert(root.left, l, r, h);
        else
            root.right = insert(root.right, l, r, h);
        return root; // 返回根节点
    }

    private int query(Node root, int l, int r) {
        if (root == null) return 0;
        // 高度
        int curH = 0;
        if (!(r <= root.l || root.r <= l)) // 是否跟这个节点相交
            curH = root.h;
        // 未剪枝
        curH = Math.max(curH, query(root.left, l, r));
        curH = Math.max(curH, query(root.right, l, r));
        return curH;
    }
}
```

##### 执行结果

```
执行用时 : 48 ms , 在所有 Java 提交中击败了 20.59% 的用户
内存消耗 : 40.9 MB , 在所有 Java 提交中击败了 25.00% 的用户
```

##### Java代码第二版本，剪枝

```java
import java.util.*;

class Solution {
    // 描述方块以及高度
    private class Node {
        int l, r, h;
        Node left, right;

        public Node(int l, int r, int h) {
            this.l = l;
            this.r = r;
            this.h = h;
            this.left = null;
            this.right = null;
        }
    }

    //
    public List<Integer> fallingSquares(int[][] positions) {
        // 创建返回值
        List<Integer> res = new ArrayList<>();
        // 根节点，默认为零
        Node root = null;
        // 目前最高的高度
        int maxH = 0;

        for (int[] position : positions) {
            int l = position[0]; // 左横坐标
            int r = position[0] + position[1]; // 右横坐标
            int e = position[1]; // 边长
            int curH = query(root, l, r); // 目前区间的最高的高度
            root = insert(root, l, r, curH + e);
            maxH = Math.max(maxH, curH + e);
            res.add(maxH);
        }
        return res;
    }

    private Node insert(Node root, int l, int r, int h) {
        if (root == null) return new Node(l, r, h);
        if (l <= root.l)
            root.left = insert(root.left, l, r, h);
        else
            root.right = insert(root.right, l, r, h);
        return root; // 返回根节点
    }

    private int query(Node root, int l, int r) {
        if (root == null) return 0;
        // 高度
        int curH = 0;
        if (!(r <= root.l || root.r <= l)) // 是否跟这个节点相交
            curH = root.h;
        // 剪枝
        curH = Math.max(curH, query(root.left, l, r));
        if (r > root.l)
            curH = Math.max(curH, query(root.right, l, r));
        return curH;
    }
}
```

##### 剪枝后执行结果

```
执行用时 : 24 ms , 在所有 Java 提交中击败了 91.18% 的用户
内存消耗 : 41.1 MB , 在所有 Java 提交中击败了 25.00% 的用户
```

剪枝后提升了百分之56%多，进步蛮明显的。

##### Java代码最终优化

```java
class Solution {
    // 描述方块以及高度
    private class Node {
        int l, r, h, maxR;
        Node left, right;

        public Node(int l, int r, int h, int maxR) {
            this.l = l;
            this.r = r;
            this.h = h;
            this.maxR = maxR;
            this.left = null;
            this.right = null;
        }
    }

    public List<Integer> fallingSquares(int[][] positions) {
        // 创建返回值
        List<Integer> res = new ArrayList<>();
        // 根节点，默认为零
        Node root = null;
        // 目前最高的高度
        int maxH = 0;

        for (int[] position : positions) {
            int l = position[0]; // 左横坐标
            int r = position[0] + position[1]; // 右横坐标
            int e = position[1]; // 边长
            int curH = query(root, l, r); // 目前区间的最高的高度
            root = insert(root, l, r, curH + e);
            maxH = Math.max(maxH, curH + e);
            res.add(maxH);
        }
        return res;
    }

    private Node insert(Node root, int l, int r, int h) {
        if (root == null) return new Node(l, r, h, r);
        if (l <= root.l)
            root.left = insert(root.left, l, r, h);
        else
            root.right = insert(root.right, l, r, h);
        // 最终目标是仅仅需要根节点更新 maxR
        root.maxR = Math.max(r, root.maxR);
        return root; // 返回根节点
    }

    private int query(Node root, int l, int r) {
        // 新节点的左边界大于等于目前的maxR的话，直接得到0，不需要遍历了
        if (root == null || l >= root.maxR) return 0; 
        // 高度
        int curH = 0;
        if (!(r <= root.l || root.r <= l)) // 是否跟这个节点相交
            curH = root.h;
        // 剪枝
        curH = Math.max(curH, query(root.left, l, r));
        if (r > root.l)
            curH = Math.max(curH, query(root.right, l, r));
        return curH;
    }
}
```

##### 执行结果

```
执行用时 : 6 ms , 在所有 Java 提交中击败了 100.00% 的用户
内存消耗 : 41.2 MB , 在所有 Java 提交中击败了 25.00% 的用户
```

##### Go语言代码，对应Java最终优化版本

```go
import (
	"fmt"
)

// 定义方块的结构体
type Node struct {
	l, r, h, maxR int
	left, right   *Node // 指针类型，难难难（大学没学好C语言的后果，一不小心bu会用）
}

func fallingSquares(positions [][]int) []int {
	// 创建返回值 使用切片 (动态数组)
	var res = make([]int, 0)
	// 根节点
	var root *Node = new(Node) // 初始化，对应类型的零值
	// 目前最高的高度
	maxH := 0
	for _, position := range positions {
		l := position[0]               // 左横坐标
		r := position[0] + position[1] // 右横坐标
		e := position[1]               // 边长
		curH := query(root, l, r)      // 目前区间的最高的高度
		root = insert(root, l, r, curH+e)
		maxH = max(maxH, curH+e)
		res = append(res, maxH)
	}
	return res
}

func insert(root *Node, l int, r int, h int) *Node {
	if root == nil {
		return &Node{
			l:    l,
			r:    r,
			h:    h,
			maxR: r,
		}
	}
	if l <= root.l {
		root.left = insert(root.left, l, r, h)
	} else {
		root.right = insert(root.right, l, r, h)
	}
	root.maxR = max(r, root.maxR)
	return root
}

func query(root *Node, l int, r int) int {
	// reflect.ValueOf(root).IsValid() 表示判断root是否为空
	// 新节点的左边界大于等于目前的maxR的话，直接得到0，不需要遍历了
	if root == nil || l >= root.maxR {
		return 0
	}
	// 高度
	curH := 0
	if !(r <= root.l || root.r <= l) { // 是否跟这个节点相交
		curH = root.h
	}
	// 剪枝
	curH = max(curH, query(root.left, l, r))
	if r >= root.l {
		curH = max(curH, query(root.right, l, r))
	}
	return curH
}

func max(l, r int) int {
	if l > r {
		return l
	}
	return r
}
```

##### 执行结果

```
执行用时 : 12 ms , 在所有 Go 提交中击败了 100.00% 的用户
内存消耗 : 5.6 MB , 在所有 Go 提交中击败了 100.00% 的用户
```

##### 来源 @ 算法无遗策 公众号

![](https://pic.leetcode-cn.com/ec06b0ca4b16578aa4e5e5dd9e28b6e13d8fdba27221b1463d76d4ea90332a46-%E6%96%87%E6%A1%88.jpg)
