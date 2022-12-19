估计极少有人用 scala 写了~~

```scala
  // 忽略合法性校验。if (_size < 1) return 0D // 保证数据的合法性
  class MovingAverage(_size: Int) {

    val queue = scala.collection.mutable.Queue[Int]() // 可变队列，仅保留数据流最大长度
    var sum = 0D // 当前队列数字总和，为了保证除法计算小数位不丢失精确，声明为 double

    def next(`val`: Int): Double = {
      if (queue.lengthCompare(_size) >= 0) sum -= queue.dequeue() // 超过最大长度，移除
      sum += `val`
      queue.enqueue(`val`)
      sum / queue.size
    }
  }
```