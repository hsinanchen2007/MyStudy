1.按照内层数组首元素进行升序排序
2.创建空列表用于保存结果列表:l
3.创建保存结果列表中元素:e
4.对e和各元素首，尾数字进行比较，按要求将尾数组加入到e列表中，或者将e追加到l中并将e重置
5.判断完成后，进行类型转换

```
object Solution {
    def merge(intervals: Array[Array[Int]]): Array[Array[Int]] = {
    var result: List[List[Int]] = List()
    if (intervals.length > 0) {
      val interv = intervals.sortBy(_.head)
      var element: List[Int] = interv.head.toList
      for (el <- interv) {
        if (element.last >= el.head && element.last < el.last) {
          element :+= el.last
        }
        else if (element.last < el.head) {
          result ::= element
          element = el.toList
        }
      }
      result ::= element
      result.reverse.map(lst => Array(lst.head, lst.last)).toArray
    } else
      result.map(_.toArray).toArray
    }
}
```

