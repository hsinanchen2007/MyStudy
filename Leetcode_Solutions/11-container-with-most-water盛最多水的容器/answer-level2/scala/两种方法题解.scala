这个题目的解题的重点在于观察两个变量 x和y
x越大越好
y越大越好
对于指针计算法：都是在寻求最大化



```
  //第一种方法，暴力破解方法
  def maxArea(height: Array[Int]): Int = {
    var max = 0
    if(height.length>1){
      for(i <- 1 to height.length-1){
        var maxLocal = 0
        for(j <- 0 to i-1){
          var min = height(i)
          if(height(i)>height(j))
            min=height(j)
          var resultLocal = (i-j)*min
          if(resultLocal>maxLocal)
            maxLocal=resultLocal
        }
        if(max < maxLocal)
          max = maxLocal
      }
    }
    return max
  }
  //第二种，指针探索法
  def maxArea(height: Array[Int]): Int = {
    var i = 0
    var j = height.length-1
    var maxarea = 0
    while (i<j){
      maxarea = math.max(maxarea,math.min(height(i),height(j))*(j-i))
      if(height(i)<height(j))
        i+=1
      else
        j-=1
    }
    return maxarea
  }
```
