# 暴力搜索:
思路简单，无脑遍历，找就完事了。
```java
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        for(int[] array:matrix)
        {
            for(int i:array)
            {
                if(i == target)
                    return true;
            }
        }
        return false;
    }
}
```
# 根据规律：
这个地方就有分歧了，因为根据题意我们按照矩阵 右上角 到 左下角 进行分割会发现右面的数比这条线大，左面的数比这条线小，所以我们可以把两个断电作为起点，从右上角找或者从左下角找

我们先来试试左下角，如果matrix中的数比目标小，那就拿matrix右面的数比较，如果matrix中的数比目标大，我们就用上面的数比

```java
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
      int n = matrix.length - 1;
      int m = 0;
    //看左下角。
      while(n >= 0 && m < matrix[0].length)
      {     
          if(matrix[n][m] > target)
          {
              //向上移动
              n--;
          }
          else if(matrix[n][m] < target)
          {
              //向右移动
              m++;
          }
          else
            return true;
      }
         return false;
    }
}
```
# 异常处理：
我们再来关注右下角，如果使用右下角来获取数组的边界就会发生一个问题：在测试数据中，又一个数据是“[]”,这个数据明显会让我门获取列方法得到一个越界的异常，我们捕捉这个异常并且将它处理(return false;)即可
```java
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        try
        {
            int n = 0;
            int m = matrix[0].length - 1;

            while(true)
            {
                if(matrix[n][m] > target)
                {
                    m--;
                }
                else if(matrix[n][m] < target)
                {
                    n++;
                }
                else
                    return true;
            }
           

        }
        catch(ArrayIndexOutOfBoundsException e)
        {
            return false;
        }
    }
}
```


