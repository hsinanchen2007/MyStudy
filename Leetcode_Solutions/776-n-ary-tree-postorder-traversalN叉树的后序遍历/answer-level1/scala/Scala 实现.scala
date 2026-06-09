执行结果：
```
代码块
```
通过
显示详情
执行用时 :
1016 ms
, 在所有 Scala 提交中击败了
100.00%
的用户
内存消耗 :
53.3 MB
, 在所有 Scala 提交中击败了
100.00%
的用户
```
//使用不可变的,leetcode中编译不过，因为版本问题，新的版本中不保留历史遗留的Stack结构
  def postorder2(root: Node): List[Int] = {
    import scala.collection.immutable.Stack
    var ret = List[Int]()
    var stack = Stack[Node]()
    stack = stack.push(root)
    while (stack.nonEmpty) {
      val (head, tail) = stack.pop2
      stack = tail
      ret = ret.:+(head.value)
      if (head.children.nonEmpty) {
        //根+先左后右，出来的顺序就是根+先右后左。翻转后就是左右根
        head.children.foreach(e => stack = stack.push(e))
      }
    }
    ret.reverse
  }

  def postorder(root: Node): List[Int] = {
    import scala.collection.mutable
    var ret = Seq[Int]()
    val stack = mutable.Stack[Node]()
    stack.push(root)
    while (stack.nonEmpty) {
      val node = stack.pop()
      if (node != null) {
        ret = ret ++ Seq(node.value)
        if (node.children.nonEmpty) {
          //先左后右，出来的顺序就是根先右后左。翻转后就是左右根
          node.children.foreach(stack.push)
        }
      }
    }
    ret.toList.reverse
  }
```

