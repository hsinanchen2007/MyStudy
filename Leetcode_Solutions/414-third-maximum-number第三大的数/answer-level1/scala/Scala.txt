### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def thirdMax(nums: Array[Int]): Int = {
        import scala.collection.mutable
     val tree = new mutable.TreeSet[Int]()
    for (i <- nums) {
      tree.add(i)
    }
    if (tree.size < 3)
      tree.last
    else {
      tree.remove(tree.last)
      tree.remove(tree.last)
      tree.last
    }    
    }
}
```