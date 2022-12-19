### 解题思路
1.统计水平方向移动次数(num_horizontal),当移动为R时,num_horizontal++,否则--;
2.统计垂直方向移动次数(num_vertical),当移动为U时,num_vertical++,否则--;
3.只有num_horizontal == num_vertical == 0时，返回True，否则False

### 代码

```java []
class Solution {
    public boolean judgeCircle(String moves) {
        int num_horizontal = 0; // 水平方向
        int num_vertical = 0;  // 垂直方向
        for(char c: moves.toCharArray()){
            if(c == 'R') num_horizontal ++;
            if(c == 'L') num_horizontal --;
            if(c == 'U') num_vertical ++;
            if(c == 'D') num_vertical --;
        }
        if(Math.abs(num_horizontal) + Math.abs(num_vertical)== 0)
            return true;
        else
            return false;
    }
}
```
```scala []
  def judgeCircle(moves: String): Boolean = {
    var num_vertical = 0
    var num_horizontal = 0
    for(c <- moves.toCharArray){
      if(c == 'R') num_horizontal = num_horizontal + 1
      if(c == 'L') num_horizontal = num_horizontal - 1
      if(c == 'U') num_vertical = num_vertical + 1
      if(c == 'D') num_vertical = num_vertical - 1
    }
    if(scala.math.abs(num_horizontal) + scala.math.abs(num_vertical)== 0) true
    else false
  }
```
