### 解题思路
此处撰写解题思路
1.似乎没有什么难度，直接遍历就好了。
2.回文整数的特点。    假设数字表示为abcdef  那么  fedcba 等于abcdef.其中abcdef都是数字。  所以每次除以10，得到当前的个数的数字，用变量new_x收集数字，并变量new_x乘以10+该数字.(不知道该怎么表述比较好)
3.要点：一、一个整数在做乘法与加法时，要注意溢出。这和第7和8题的考点一样。二、负数肯定不是正确答案。三、0肯定是正确答案。四、最后一位是0的肯定不是正确答案，因为不可能有0开头的数字。
4.我是一次性完成的，没有借鉴别人的答案。
5.作者：法学小鑫（法学本科+计算机双学位+软件工程硕士）
### 代码

```scala
object Solution {
    def isPalindrome(x: Int): Boolean = {
        //x是一个整数。可能是负整数 也可能是正整数，或者是0
        //显然x为负数的时候，他不是一个回文数，直接排除
        if(x<0){
            return false
        }else if(x==0){
            //等于0，是回文数
            return true
        }else{
            //接下来只用判断正整数的情况。
            var quotient:Int=x //表示商
            var remaider:Int=0//表示余数
            var divisor:Int=10//表示除数
            val max_number=Int.MaxValue/10
            val max_last_index=Int.MaxValue %10
            var new_x=0//翻转后的字符串
            while(quotient !=0){
                remaider=quotient % divisor
                quotient /= divisor
                //判断new_x的范围是否超出了大小。
                if(new_x>max_number || remaider>max_last_index && new_x==max_number){
                    //说明new_x超出了大小。若x是回文数字， 那么new_x也是回文数字，不会超出大小。所以x一定不是回文
                    return false
                }else{
                    new_x = new_x*divisor + remaider
                }
            }
            //现在形成了new_x与x 比较他们的大小即可
            return new_x==x
        }
    }
}
```