### 解题思路
使用快速排序排序数组 使用slice切割指定个数的元素

### 代码

```scala
object Solution {
def getLeastNumbers(arr: Array[Int], k: Int): Array[Int] = {
    if (arr.size == 0) {
      Array(0)
    } else {
      val arrSort: List[Int] = quickSort(arr.toList)
      arrSort.slice(0, k).toArray
    }
  }

  /**
   * 在scala的集合中有一个方法能够将集合分成两半，可以存储满足条件的数据
   * partition--->分区
   * 一般的基准元素就是每次进行排序的第一个元素。
   *
   */
  def quickSort(arr: List[Int]): List[Int] = {
    arr match {
      case Nil => Nil
      case List() => List()
      case _ => {
        val (smaller, larger) = arr.tail.partition(num => num < arr.head)
        quickSort(smaller) ::: (arr.head :: quickSort(larger))
      }
    }
  }
}
```