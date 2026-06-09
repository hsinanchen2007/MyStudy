
# **思路：将每一个字符都设置一个对应的数字，再用并查集合并有关联关系的集合，最后res直接按照代入数字算除法。**

1. 将每个字符映射成集合中的一个节点  比如 [a,c]  他们对应的values的值是 3 ，那我不管你a和c到底是什么，我可以假设你a为3  c为1，只要满足a/c = 3就行了。
2. 这样我可以给每个字符都设置一个对应的数字，我设的数字只要满足题目给定的所有关系就ok，最后求结果我只要把字符对应的数字代进去直接除就行了。
3. 但是有个问题，这样搞的话，假设[a,b]的values为2  设置a=2,b=1   [c,d]的values为3  c=3  d=1  那这时候4个字符都有数字了，结果要你求a/c，a/c实际上是
无法求出来的，这你如果还直接代进去的话那就GG了。。。
4. 那什么样的是算不出来的？ 两者没有关联关系的，毫不相干的，就无法计算，那判断两个点有没有连接。。。这不就是并查集吗（好吧第一反应是无向图...，对其dfs或者bfs也可判断，但我看别人答案都是并查集，所以直接抄的并查集。。。╮(╯▽╰)╭）

**并查集的两个作用**
1. 查询元素a和元素b是否属于同一组
2. 合并元素a和元素b所在的组
（好像就这两个作用，没有其他的了，有的话请大佬留言指出）


- 接下来根据所有的关联关系equations来构建集合就行，这个构建好的集合（树）就是一个叫并查集的东西
- 构建完之后按照假设的数字带入算除法就行，并查集就是用来判断是不是同一个集合用的

```go
//这里用struct来表示并查集的节点
type Node struct{
    Value float64
    Parent *Node
}

//初始化Node函数
func NewNode(value float64) *Node {
    node := &Node{
        Value:value,
    }
    node.Parent = node
    return node
}

//万年不变的并查集特性之一findParent函数
func findParent(node *Node) *Node {
    if node == node.Parent {
        return node
    }
    node.Parent = findParent(node.Parent) //这里赋值只是压缩下路径，方便下次找根节点，直接返回findParent(node.Parent)也一样
    return node.Parent
}

//合并两棵树（或者说两个集合）为一棵树
//node1和2都为一个集合节点，num就是本次node1的值除以node2的值的商（就是values数组中对应的值），maps保存了所有节点，用于找出node1所在集合的所有节点，作用下面有说
func union(node1,node2 *Node, num float64, maps map[string]*Node){
    p1,p2 := findParent(node1),findParent(node2)
    if p1 != p2 { //当两个点不在同一个集合的时候才需要合并
        //把一颗子树挂到另一棵树的时候，要把挂上去的树乘以一个和父树的比率
        //这个比率要保证两棵树的所有节点的value相除都是正确的结果
        //比如A树中  a/b = 3  其中 a初始化为3，b初始化为1
        //B树中  c/d = 5 其中c为5，d为1
        //原本A树和B树是不相干的两个集合，此时有一个条件为 a/c = 5，那么就可以将A集合中的a和B集合中的c节点联系起来，两个集合最终就能连成一个集合
        //那么直接将A挂到B上来的话，a为3c为5  3/5很明显 != a/c != 5，因此要将A树挂到B树上的话，就要将A树整体扩大或者缩小到可以满足a/c=5的地步
        //那这个倍数怎么算？ a/c = 5   a=c*5，那么我只要将a变成c*5的值就行了,那a乘以多少=c*5呢，设为ratio,   a * ratio=c*5    =》 ratio = c*5/a    

        //这里设node1为A树节点，node2为B树节点，将A树挂到B树
        ratio := node2.Value * num / node1.Value
        
        //将A树所有节点整体扩大，这样A树里面的所有除法结果依然不变，并且能兼容B树的数字
        for k,v := range maps { //找出所有A树上的节点，怎么找？同一个父亲就是同一个树（集合）里面的
            if findParent(v) == p1 {
                maps[k].Value *= ratio
            }
        }
        //挂到p2上
        p1.Parent = p2
    }
}

func calcEquation(equations [][]string, values []float64, queries [][]string) []float64 {
   res := make([]float64,0)
   maps := make(map[string]*Node)

   for k,v := range equations {
       v1,ok1 :=  maps[v[0]]
       v2,ok2 :=  maps[v[1]]
       if !ok1 && !ok2 {
           //两个之前都没有出现过
           p1,p2 := NewNode(values[k]),NewNode(1)
           maps[v[0]],maps[v[1]] = p1,p2
           p1.Parent = p2  //组成树
       } else if !ok1 {
           //ok1没有但是ok2有，把v1挂上去
           p2 := findParent(v2)
           //v1 的 值该设多少？ v1 / v2 = k    v1 = v2 * k
           p1 := NewNode(v2.Value * values[k])
           maps[v[0]] = p1
           p1.Parent = p2
       } else if !ok2 {
           //ok1有 ok2没有，把ok2挂上去
           p1 := findParent(v1)
           //v1/v2 = k   v2 = v1/k
           p2 := NewNode(v1.Value / values[k])
           maps[v[1]] = p2
           p2.Parent = p1
       } else {
           //两个都有，合并
           union(v1,v2,values[k],maps)
       }
   }

   //合并完并查集之后开始查找
       for _,v := range queries {
           v1,ok1 :=  maps[v[0]]
           v2,ok2 :=  maps[v[1]]

           //两个字符都出现过并且属于同一个集合，不同集合的无法计算，比如  A树 a/b    B树 c/d， 此时要算 a/c = 无法计算
           if ok1 && ok2 && findParent(v1) == findParent(v2) {
               res = append(res,v1.Value/v2.Value)
           } else {
               res = append(res,-1.0)
           }
       }

   return res
}
```