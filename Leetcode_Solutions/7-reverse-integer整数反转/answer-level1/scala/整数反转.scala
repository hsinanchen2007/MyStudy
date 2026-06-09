一,这个问题,看了官方的答案,并对官方的答案进行了思考,简化一下实现过程
1. 首先整数的最大值是2147483647,最小值是-2147483648,可以看出都是十位数,并且不对称
2. 其次,如果是最小值反转,肯定是溢出,排除掉,剩下的就对称了,都可以转到正数的情况
3. 其次,十位数以下可以直接计算,不用考虑反转溢出
4. 最后,只有十位数才可能存在反转溢出



```

object Solution {
  def reverse(x: Int): Int = {
    if(x == Int.MinValue || x == 0){
      return 0
    }
    val sign= if(x > 0 ) 1 else -1
    var xx=x.abs
    val queue=scala.collection.mutable.Queue[Int]()
    while (xx!=0){
      queue.enqueue(xx%10)
      xx/=10
    }
    var sum=0
    if(queue.length<10){
      while (!queue.isEmpty){
        sum = sum *10 + queue.dequeue()
      }
    }else{
      while (!queue.isEmpty){
        val q=queue.dequeue()
        if(sum < Int.MaxValue/10 || (sum == Int.MaxValue/10 && q<=7)){
          sum = sum *10 + q
        }else{
          return 0
        }
      }
    }
    
    return sum*sign
  }
}


```
