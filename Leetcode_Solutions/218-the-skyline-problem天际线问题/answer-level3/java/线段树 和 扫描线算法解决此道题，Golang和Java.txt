### 解题

光看题目描述似乎觉得很难，但是学习过线段树就会觉得这道题变得很容易。不信，来试试看下面的图：

![线段树](https://pic.leetcode-cn.com/eb986dadbaa7f393e8e2eff4db7048495727c4a8d212c8053d9676fe90cabf87.png)

我们可以把输入列表作为一个顶点，按照输入列表的长度选取中间的值，建议使用这个方式： `mid := l + (r-l)/2` 选择中间值，然后进行分治算法。

直到当前输入列表的长度为1，说明不能再分了，在这个地方作为结束条件，然后返回到另外路径划分其它的输入列表。

例如我们划分到 [[2 9 10]] 的时候，当前输入列表的长度为1，不能再进行分治了。

[[2 9 10]]表示的是一个建筑物，分别是左右边缘的横坐标和高度。题目已经将天际线定义为水平线左端点的集合，如[[2 9 10]]关键点集合为[[2 10] [9 0]]，分别是一个建筑物上的左上端点和右下端点。

同理，[[3 7 15]]的关键点集合为[[3 15] [7 0]]。

关键的一点来了，我们得到了[[2 9 10]] 和 [[3 7 15]] 两个集合之后，要求在满足题目天际线情况下，怎么把这两个集合进行合并呢？意思是合并之后的集合，也是满足天际线的，如下面合并的过程：

![合并](https://pic.leetcode-cn.com/7566920bd396222e1d15fdceb4480a7313433e1ca9ef9a6f5ff8a4be89ee3d02.png)

其实我们在题目标签看到了Line Sweep，[ 线扫描或扫描线 ] ，扫描线可以想象成一条向右扫过平面的竖直线，也是一个算法，一般是玩图形学的。

接着上面的步骤，可以通过扫描线算法将两个关键点集合进行合并。

如下图，扫描线从两个集合的起始点，同时向右移动，接触到第一个关键点，则判断这一个关键点是不是满足天际线的，如果是，则将这个关键点添加到“父”集合中；如果不是，则继续同时移动到下一个关键点。

![扫描线](https://pic.leetcode-cn.com/efdad052ba4020956d12202d0123b3f1a1f083d4979ddbe976340914e00bb9ce.png)

但如何判断是否是属于“父”集合中的关键点呢？可以创建两个集合（“子”）的目前高度，然后多方角度找到满足关键点的条件。

扫描线移到[2 10]关键点时，10要大于rpre的，可以满足；

扫描线移到[3 15]关键点时，lpre此时目前的高度为10，而15要大于10的，可以满足；

扫描线移到[7 10]关键点时，rpre大于lpre可以满足，反之就不满足；

接着有一个集合已经遍历完了，剩下的集合的关键点肯定是满足的，因为没有其它的集合可以阻挡到这个集合，所以直接就是满足。

##### Go语言代码，使用线段树

```go
// 来源公众号 @ 算法无遗策
package main
// 粘贴到LeetCode代码控制台时，需要删去main包和main入口函数
import (
	"fmt"
)

// 线段树
func getSkyline(buildings [][]int) [][]int {
	len := len(buildings)
	if len == 0 {
		return nil
	}
	return segment(buildings, 0, len-1)
}

func segment(buildings [][]int, l int, r int) [][]int {
	// 创建返回值
	var res [][]int
	// 结束条件
	if l == r {
		return [][]int{{buildings[l][0], buildings[l][2]}, {buildings[l][1], 0}}
	}
	// 取中间值
	mid := l + (r-l)/2
	// 左递归
	left := segment(buildings, l, mid)
	// 右递归
	right := segment(buildings, mid+1, r)
	// 左右合并
	// 创建left 和 right 的索引位置
	var m int = 0
	var n int = 0
	// 创建 left 和 right 的目前高度
	var lpre int = 0
	var rpre int = 0
	for m < len(left) || n < len(right) {
		// 一边遍历完，则全部添加另一边
		if m >= len(left) {
			res = append(res, right[n])
			n++
		} else if n >= len(right) {
			res = append(res, left[m])
			m++
		} else { // swip line
			if left[m][0] < right[n][0] {
				if left[m][1] > rpre {
					res = append(res, left[m])
				} else if lpre > rpre {
					res = append(res, []int{left[m][0], rpre})
				}
				lpre = left[m][1]
				m++
			} else if right[n][0] < left[m][0] {
				if right[n][1] > lpre {
					res = append(res, right[n])
				} else if rpre > lpre {
					res = append(res, []int{right[n][0], lpre})
				}
				rpre = right[n][1]
				n++
			} else { // left 和 right横坐标相等
				if left[m][1] >= right[n][1] && left[m][1] != max(lpre, rpre) {
					res = append(res, left[m])
				} else if left[m][1] <= right[n][1] && right[n][1] != max(lpre, rpre) {
					res = append(res, right[n])
				}
				lpre = left[m][1]
				rpre = right[n][1]
				m++
				n++
			}
		}
	}
	return res
}

func max(l, r int) int {
	if l > r {
		return l
	}
	return r
}

func main() {
	buildings := [][]int{{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}}
	fmt.Println(getSkyline(buildings))
}
```

##### 线段树执行结果

```
执行用时 : 20 ms , 在所有 Go 提交中击败了 93.75% 的用户
内存消耗 : 6.7 MB , 在所有 Go 提交中击败了 72.73% 的用户
```

其实，这道题可以不用线段树，单独用扫描线算法可以解决这道题的。不过，线段树因为分治算法的关系，时间复杂度要比没有线段树的小。

具体怎么做可以看下面的动画：

![扫描线算法动画](https://pic.leetcode-cn.com/33fc07812f1bba4bef1b40f6594da1cbd2fdfbf99b142a032c98f98b67e7db06.gif)

使用扫描线，从左向右扫过，如果遇到左端点，将高度入堆；如果遇到右端点，将高度从堆中删除。

这样做有什么意义呢？

因为高度入堆的时候，获取这个堆的最大值，判断一下最大值是否和前一关键点的当前高度是否相等，如果不相等，说明这是一个拐点，也是天际线的关键点，然后更新当前高度，即当前高度等于最大值；

高度出堆的时候，将这个高度从堆中删除，接着获取这个堆中的最大值，判断一下这个最大值和前一关键点的当前高度是否相等，如果不相等，说明这也是一个拐点。

但是如何区分左右端点的高度呢？因为遇左端点要将高度入堆，遇右端点要将高度出堆。

我们可以这样设计，将左端点的高度设置成负数，右端点的高度还是原来值。这样出入堆的时候，可以根据正负数来决定入堆还是出堆。

因为高度可以有重复性，而且我们要最大堆，所以这个堆要设定成可以有重复数字的最大堆。

##### Go语言代码，单独使用线扫描法

```go
import (
	"container/heap"
	"fmt"
	"sort"
)

// 来源公众号 @ 算法无遗策

// 线扫描法
func getSkyline(buildings [][]int) [][]int {
	// 创建返回值
	var res [][]int
	// 保存所有可能的拐点
	var pairs = make([][2]int, len(buildings)*2) // 切片 类似动态数组
	index := 0
	// 将每一个建筑分成两个部分
	for _, build := range buildings {
		pairs[index][0] = build[0]
		pairs[index][1] = -build[2]
		index++
		pairs[index][0] = build[1]
		pairs[index][1] = build[2]
		index++
	}
	// pairs进行升序
	sort.Slice(pairs, func(i, j int) bool {
		if pairs[i][0] != pairs[j][0] {
			return pairs[i][0] < pairs[j][0]
		}
		return pairs[i][1] < pairs[j][1]
	})
	// 最大堆？
	maxHeap := &IntHeap{}
	// 记录之前的高度
	prev := 0
	// 遍历
	for _, pair := range pairs {
		if pair[1] < 0 {
			heap.Push(maxHeap, -pair[1])
		} else {
			for i := 0; i < maxHeap.Len(); i++ {
				if maxHeap.Get(i) == pair[1] {
					heap.Remove(maxHeap, i)
					break
				}
			}
		}
		top := maxHeap.Top()
		if top != prev {
			res = append(res, []int{pair[0], top})
			prev = top
		}
	}
	return res
}

// Go语言中没有像Java语言一样有这个PriorityQueue类的结构体的，需要自己实现
// 定义堆
type IntHeap []int

func (h IntHeap) Len() int          { return len(h) }
func (h IntHeap) Get(index int) int { return h[index] }
func (h IntHeap) Less(i, j int) bool {
	if i < len(h) && j < len(h) {
		return h[i] > h[j] // > 表示最大堆，< 表示最小堆
	}
	return true
}

func (h IntHeap) Swap(i, j int) {
	if i < len(h) && j < len(h) {
		h[i], h[j] = h[j], h[i]
	}
}

func (h *IntHeap) Push(x interface{}) { *h = append(*h, x.(int)) }

func (h *IntHeap) Pop() interface{} { // 去掉最后一个数，要注意指针
	old := *h
	l := len(old)
	*h = old[0 : l-1]
	return h
}

func (h IntHeap) Top() int {
	if len(h) != 0 {
		return h[0]
	}
	return 0
}
```

##### 线扫描法执行结果

```
执行用时 : 52 ms , 在所有 Go 提交中击败了 65.63% 的用户
内存消耗 : 6.4 MB , 在所有 Go 提交中击败了 72.73% 的用户
```

##### Java代码，使用线段树

```java
import java.util.*;

class Solution {

// 来源公众号 @ 算法无遗策

    // 线段树
    public List<List<Integer>> getSkyline(int[][] buildings) {
        int len = buildings.length;
        if (len == 0) return new ArrayList<>();
        return segment(buildings, 0, len - 1);
    }

    private List<List<Integer>> segment(int[][] buildings, int l, int r) {
        // 创建返回值
        List<List<Integer>> res = new ArrayList<>();

        // 找到树底下的结束条件 -> 一个建筑物
        if (l == r) {
            res.add(Arrays.asList(buildings[l][0], buildings[l][2])); // 左上端坐标
            res.add(Arrays.asList(buildings[l][1], 0)); // 右下端坐标
            return res;
        }

        int mid = l + (r - l) / 2; // 取中间值

        // 左边递归
        List<List<Integer>> left = segment(buildings, l, mid);

        // 右边递归
        List<List<Integer>> right = segment(buildings, mid + 1, r);

        // 左右合并

        // 创建left 和 right 的索引位置
        int m = 0, n = 0;
        // 创建left 和 right 目前的高度
        int lpreH = 0, rpreH = 0;
        // 两个坐标
        int leftX, leftY, rightX, rightY;
        while (m < left.size() || n < right.size()) {

            // 当有一边完全加入到res时，则加入剩余的那部分
            if (m >= left.size()) res.add(right.get(n++));
            else if (n >= right.size()) res.add(left.get(m++));

            else { // 开始判断left 和 right
                leftX = left.get(m).get(0); // 不会出现null，可以直接用int类型
                leftY = left.get(m).get(1);
                rightX = right.get(n).get(0);
                rightY = right.get(n).get(1);

                if (leftX < rightX) {
                   if (leftY > rpreH) res.add(left.get(m));
                   else if (lpreH > rpreH) res.add(Arrays.asList(leftX, rpreH));
                    lpreH = leftY;
                    m++;
                } else if (leftX > rightX) {
                   if (rightY > lpreH) res.add(right.get(n));
                   else if (rpreH > lpreH) res.add(Arrays.asList(rightX, lpreH));
                    rpreH = rightY;
                    n++;
                } else { // left 和 right 的横坐标相等
                	if (leftY >= rightY && leftY != (lpreH > rpreH ? lpreH : rpreH))
                        res.add(left.get(m));
                    else if (leftY <= rightY && rightY != (lpreH > rpreH ? lpreH : rpreH))
                        res.add(right.get(n));
                    lpreH = leftY;
                    rpreH = rightY;
                    m++;
                    n++;
                }
            }
        }
        return res;
    }
}
```

##### Java执行结果

```
执行用时 : 6 ms , 在所有 Java 提交中击败了 99.53% 的用户
内存消耗 : 44 MB , 在所有 Java 提交中击败了 57.65% 的用户
```

##### Java代码单独使用扫描线法

```java
// 线扫描法   来源公众号 @ 算法无遗策
public List<List<Integer>> getSkyline2(int[][] buildings) {
    // 创建返回值
    List<List<Integer>> res = new ArrayList<>();
    // 保存所有的可能拐点
    Set<Pair<Integer, Integer>> pairs = new TreeSet<>(
        (o1, o2) -> !o1.getKey().equals(o2.getKey()) ? o1.getKey() - o2.getKey() : o1.getValue() - o2.getValue()); // 二元组
    // 将每一个建筑分成两个部分
    for (int[] build : buildings) {
        pairs.add(new Pair<>(build[0], -build[2]));
        pairs.add(new Pair<>(build[1], build[2]));
    }
    // 优先队列的最大堆
    PriorityQueue<Integer> queue = new PriorityQueue<>((o1, o2) -> o2 - o1); // 最大堆
    // 记录之前的高度
    int prev = 0;
    // 遍历
    for (Pair<Integer, Integer> pair : pairs) {
        if (pair.getValue() < 0) queue.offer(-pair.getValue()); // 左端点 高度入堆
        else queue.remove(pair.getValue()); // 右端点 高度出堆
        Integer cur = queue.peek() == null ? 0 : queue.peek(); // 获取最大堆的当前顶点，当null时置为0
        if (prev != cur) {
            res.add(new ArrayList<Integer>() {{
                add(pair.getKey());
                add(cur);
            }});
            prev = cur;
        }
    }
    return res;
}
```



关注「算法无遗策」，一起领悟算法的魅力，大家加油 (●'◡'●)