### 解题思路 暴力求解
我们需要根据起点去查找可以到达的终点机场，

这个查找操作很频繁，我们不想每次都在所有机票里线性查找，于是可以把这个对应关系放到哈希表。

key表示起点机场，value表示对应的到达机场，并且一个起点可以对应多个到达机场，因此value用一个list表示。

有了这个辅助哈希表，我们就可以用O(1)的时间，找出从某个机场出发可以到达哪些机场，

由于题目说了，如果存在多个有效行程，要返回字典序最小的那一个。

因此在有多个机场可选时，我们应该先去机场代号中字典序最小的那个机场，

这样一来，我们找到第一个有效行程，就会是字典序最小的行程，于是对于辅助哈希表中的value，我们还需要做一次排序，

把到达机场按从小到大排序，

对于递归终止的判断，除了看所有可达机场是否已经被访问过，

还有一种更简单的判断方式，就是看行程中的机场数量，是否等于机票数量+1，

如果刚才递归求解的路径，到最后发现不是一个有效的行程，我们就一层层的退递归，向后回溯，回溯时，要做两件事。

* 把已经加入行程中的机场移除
* 把哈希表中标记为已访问的机场重置为未访问

这样我们就能退回到前面的位置，重新选择别的路径，暴力解法，最坏情况下要穷举所有路径排列，数量是n的阶乘。

不过我们的出发机场是固定的，并不是从n个机场中随便挑一个出发，

于是排列数量除以n，表示第一个出发机场固定为n个机场中的一个，对于具体的一个排列，我们需要递归n次来得到，

于是再乘以n因此暴力法的时间复杂度是O(n!),空间复杂度来自两个方面，

* 额外使用一个大小规模为n的辅助哈希表
* 递归过程中使用的递归调用栈，调用栈的最大深度是n

因此总的空间复杂度是O(n).

### 代码

```golang
// 辅助数据结构Pair方便存储机场名称已经对应的访问情况
type Pair struct {
   First  string
   Second bool
}

func NewPair(first string, second bool) Pair {
   return Pair{first, second}
}

// 辅助递归函数，
// 输入出发机场from，
// 行程中机场总数total，用于保存行程的result，已经保存的出发机场和到达机场的对应关系的Map
// 输出是一个布尔值，表示是否已经找到一个有效行程
// map 中key的类型是string表示出发机场的名称，value是一个list，其中每个元素时一个Pair，
// Pair中string表示到达机场的名称，布尔值表示这个机场是否已经访问过
// 在递归的过程中需要使用和修改
func dfs(from string, total int, result *[]string, maps map[string][]Pair) bool {
   // 进入函数第一件事先检查result大小是否已经等于total
   if len(*result) == total { // 说明已经找到一条有效行程
      return true // 返回true
   }
   // 从map中取出from机场和到达机场的列表
   tos := maps[from]
   if tos == nil { // 如果为空
      return false // 说明票没有用完就结束了.不是一条有效的行程，返回false
   }
   // 不为空的话，就遍历列表中的Pair
   for i := range tos {
      if tos[i].Second { // 如果Pair到达机场为true说明已经访问过了
         continue // 继续看下一对数据
      }
      // 如果当前到达机场未被访问
      tos[i].Second = true                        // 就访问它，把Pair中的Second设置为true
      *result = append(*result, tos[i].First)     // 然后把First加入到结果列表
      if dfs(tos[i].First, total, result, maps) { // 接着就以到达机场作为出发机场，递归调用自己，
         return true // 如果最终返回true，这里就可以提前返回true
      }
      // 否者说明以上路径不能形成一个有效行程
      // 刚加入result末尾的机场移除
      *result = (*result)[:len(*result)-1]
      // 并把它的访问情况重置为false
      tos[i].Second = false
   }

   return false // 循环结束或如果没有提前返回true则返回false
}

// 暴力解法 Time: O(n!), Space: O(n)
func findItinerary1(tickets [][]string) []string {
   // key存储出发机场，value存储到达机场列表和它们的访问情况
   maps := make(map[string][]Pair)
   for _, e := range tickets { // 遍历机票
      // 机票中第0个元素表示出发机场
      // 第1个元素表示达到机场
      // 如果哈希表中不存在等于当前出发机场的key
      if _, ok := maps[e[0]]; !ok {
         // 就以当前出发机场为key
         maps[e[0]] = nil
      } // 然后取出当前出发机场的列表,
      // 加入一个新的Pair,存储的是当前到达机场以及它的访问情况,初始为false表示未被访问
      maps[e[0]] = append(maps[e[0]], NewPair(e[1], false))
   }
   // 接下来对map中每个Pair列表都进行排序
   for _, v := range maps {
      // 按照Pair中的first即机场名称进行排序
      // sort.Sort(ByFirst(list))
      sort.Slice(v, func(i, j int) bool {
         return v[i].First < v[j].First
      })
   }
   total := len(tickets) + 1        // 定义行程中机场的数量total为机票的数量+1
   var result []string              // 定义保存机场列表的result
   result = append(result, "JFK")   // 第一个出发机场总是"JFK"把它加入到result中
   dfs("JFK", total, &result, maps) // JFK作为出发机场，做深度优先遍历，查找有效行程
   return result                    // 递归结束后result中保存的就是字典序最小的有效行程，返回它即可
}
```

### 解题思路 Hierholzer算法
暴力解法虽然简单直观，但是时间复杂度太高，接下来介绍一种更高效的方法，

Hierholzer算法，在此之前，简单介绍图论知识。这个题目本质上可以抽象成这样一个问题，

> 在一个连通的有向图中，寻找一条固定起点的欧拉路径。
> 欧拉路径是将图中每一条边都正好访问一次的路径。

这个题目给我们一组机票，而每张机票包含起点和终点，因此我们只要把所有机票的起点和终点都用一条有向边连接起来，

就会得到一个有向图，并且题目说了至少会包含一个有效行程，这就意味着我们从一点出发，一定存在一条欧拉路径。

一个连通的有向图中存在欧拉路径的充分必要条件是：

* 存在一个节点，它的出度比入度大1，同时存在另一个节点，它的入度比出度大1，其他所有节点的入度都等于出度。
* 或者图上所有节点的入度都等于出度，这时的欧拉路径又叫做欧拉环或欧拉回路。

如果图上存在欧拉环，那么起点和终点是同一个节点，也就是说，从起点出发然后还是回到起点，

否则如果图上存在的是一条不闭合的欧拉路径，那么出度比入度大1的节点是起点，而入度比出度大1的节点是终点，

欧拉路径存在的充分必要条件是Hierholzer算法的关键依据，针对这个题目，

Hierholzer算法可以描述如下：

* 从一个节点出发，对有向图进行深度优先遍历，并且把访问过的边删除。
* 如果当前节点没有可移动的路径，则把当前节点倒着插入节点访问序列。

接着分析一个这个算法为什么是正确的，我们知道题目给出的机票，一定可以形成包含一条欧拉路径的有向图，

根据刚才提到的对于一个连通有向图中存在欧拉路径的充要条件，这个有向图中除了起点和终点，所有其他节点入度都等于出度，

对于这些节点，你可以进入就一定可以离开，因此如果我们进入一个节点却无法离开，那就只要一种可能，

那个节点是当前欧拉路径的终点，由于是终点，于是我们要倒着插入节点访问序列，而不是从后面追加到访问序列，

找到一个终点后，退递归回到上一层，重复相同的操作，不断把剩余图的欧拉路径终点倒着插入节点访问序列，

最后我们得到的节点访问序列，就是一条欧拉路径，由于我们每次访问节点，都优先访问字典序较小的节点，

因此得到的第一个有效行程，就是字典序最小的有效行程。

标准的Hierholzer算法时间复杂度是O(n),因为每条边只需要访问一次，并且一条边的访问时间是O(1),

但在我们这个题目中，由于我们要寻找的是字典序最小的有效行程，因此可以使用最小堆来维护一个起点机场所对应的终点机场，

每次取完堆顶元素，会花费logn的时间来调整最小堆，因此时间复杂度是O(nlogn),

空间复杂度和暴力法一样，来自辅助哈希表和递归调用栈，同样是O(n)。


### 代码

```golang
// 辅助递归函数
// 输入出发机场from,保存行程的结果列表
// 保存出发机场和到达机场的对应关系map,与暴力解法相比value中存储的是优先队列
// 每次都是取出字典序最小的机场
func hierholzer(from string, result *[]string, maps map[string][]string) {
   //tos := maps[from] // 首先从哈希表中取出机场from对应的所有到达机场tos
   for len(maps[from]) > 0 { // 如果tos不为nil而且还有未使用的机场
      // 把tos中字典序最小的机场取出作为出发机场,递归调用自己
      next := maps[from][0]
      maps[from] = maps[from][1:]
      hierholzer(next, result, maps)
   }
   // 如果from没有可去的到达机场，就将它添加到结果的最前面
   *result = append(*result, from)
}

// Hierholzer算法 Time: O(n*log(n)), Space: O(n)
func findItinerary(tickets [][]string) []string {
   // 定义辅助哈希表key是出发机场，value是出发机场可去的所有到达机场，存储在优先队列中
   maps := make(map[string][]string, len(tickets)+1)
   for _, e := range tickets { // 遍历机票
      // 机票中第0个元素表示出发机场
      // 第1个元素表示到达机场
      // 如果哈希表中不存在等于当前出发机场的key
    //   if _, ok := maps[e[0]]; !ok {
    //      // 就以当前出发机场为key，存入一个空的优先队列
    //      maps[e[0]] = []string{}
    //   }
      maps[e[0]] = append(maps[e[0]], e[1]) // 把到达机场加入到优先队列
   }

   // 对所有的到达机场进行排序
   for k := range maps {
      sort.Strings(maps[k])
   }

   var result []string // 定义保存行程的结果列表
   hierholzer("JFK", &result, maps)
   for i := 0; i < len(result)/2; i++ {
      j := len(result) - i - 1
      result[i], result[j] = result[j], result[i]
   }
   return result
}
```