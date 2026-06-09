### 解题思路
此处撰写解题思路
author 法学小鑫（本科法律+双学位计算机+硕士软件工程）
我的做法是按照标答实现的。关于这道题目的思路，不必要在阐述了。
1.我先说一下可能存在的错误解法。以前我计算机《数字逻辑》的时候讲了一些十进制的码。比如BCD，8421，5421等等。我最开始的思路是把数字从二进制的角度交换。但是我们Int类型的数据，采用的并不是十进制码。必须要经过计算才能解决本题目，不可能通过交换头四位 尾四位码来做到交换本题的头与尾。
2.官方题解的超出常人理解的地方。
    为什么突然蹦出来了一个7 和 -8.
  因此我们解释了7和-8的来源。
3.不明白的地方，我的做法只打败了11%的人（时间和空间都是），毕竟我已经是官方答案修改过来了。因此有小伙伴知道原因，可以联系我。我的邮箱1300802930@qq.com。
4.官方题解每次循环都要计算 最大值/10 和最小值/10 以及进行商的比较。  
  所以我们先计算出来 最大值/10：max_Number 最小值/10：min_Number,最大商max_last_data(7的来源) 最小商min_last_data（-8的来源）
5.最后要说两点。问：(x*10)/10==x的做法 答：（x*10）/10要经过乘除法，比加减法以及比较消耗的时间长，看到别人的做法打败了100%的用户，我有点不明白
               问：为什么负数也可以这样做。（正数好理解） 答：负数除以整数  除数的符号取决与 除数与被除数，商的符号与被除数（也就是本例的负数）相同。
### 代码

```scala
object Solution {
    def reverse(x: Int): Int = {
         //    现在输入的x是一个整数，我们要输出他的翻转。但是翻转的过程中可能会遇到溢出的情况，所以需要判断
    //    1.慢慢的用除法去记住，当前结果2.判断最后一步是否溢出。
    //    定义新的x与每次除法之后商，除数
    var new_x=0;
    var quotient:Int=x; // quotient表示商
    var remainder:Int=0; //remainder表示余数
    var divisor:Int=10;   //divisor表示除数
    val max_Number=Int.MaxValue/divisor
    val min_Number=Int.MinValue/divisor
    val max_last_data=Int.MaxValue % divisor
    val min_last_data=Int.MinValue % divisor
    // 当qutient商为0的时候，说明循环结束了
    while(quotient!=0){
      remainder=quotient % divisor
      quotient=quotient / divisor
      if(new_x > max_Number || new_x==max_Number && remainder>max_last_data){
      return 0
      }else if(new_x < min_Number || new_x==min_Number && remainder < min_last_data){
        return 0
      }
      new_x =new_x*divisor + remainder
    }
    return new_x
    }
}
```