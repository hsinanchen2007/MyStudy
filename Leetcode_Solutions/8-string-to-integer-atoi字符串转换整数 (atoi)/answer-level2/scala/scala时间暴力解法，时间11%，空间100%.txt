1. 这是暴力解法，思维与编码难度大，考虑的问题多。时间复杂度高或者空间复杂度高都无话可说
2. 最好的解法——最有扩展力的解法，正则表达式。（不一定是时间，空间最优的解法）（为什么说他最优呢，因为阿里巴巴等公司要是考这种题目，就是很复杂的模式，起码5个到6个，要是暴力解法，不仅思维难度大，容易错，还消耗时间长。因此，非常有必要重温正则表达式。此外，不仅仅是重温表达式，至少正则表达式库（re）的实现你要会，你才敢说自己真的会这道题目。）
3. 我会去看那些双100的解法。
4. 作者：法学小鑫（法学本科+计算机双学位+软件工程硕士）
——————————————————————————————————————————————————
下面是解法。
——————————————————————————————————————————————————
1. 整个程序分为两个代码块。一个是判断空格，另外一个是判断数字。
2. 判断空格模式的时候，要注意当前遍历的字符是（空格，正负号以及数字） 不是 返回默认值
3. 判断数字模式的时候，要注意当前遍历的字符是（数字）不是 返回默认值
4. 判断数字的时候，要比较当前数字是否是超出了大小。和第七题很像 
5. 最后两个模式完毕的时候，要判断当前是否有数字。因为可能一直在判断空格模式，没有进入数字模式。
```
import util.control.Breaks._
object question08 {
    def myAtoi(str: String): Int = {
        //一定要读题目str是输入的字符串。
        //需要的是转换成为整数int，而不是小数。所以判断标准更容易一些
//        for(i<- Range(0,str.length){
//            这是使用Range的形式的写法
//        }
//        其实我们可以分为二个阶段来判断。分别是判断空格，判断数字，
//  在判断空格阶段，需要当前字符为空格或+- 数字。若为空格，则依然处于判断空格阶段，若为+-数字，则进入判断数字阶段，否则返回
//        在判断数字阶段，需要当前字符为0-9.否则返回。并且需要当前数字阶段存在数字，不能为空。
        var space=true //指示空格阶段
        var number=false //指示数字阶段
        var sign='+'   //符号
        var has_num=true //指示当前数字是否为空
        var ans=0      //除符号的值
        val default=0  //不符合条件，默认的返回值。
        val max_number=Int.MaxValue/10 //最大值/10
        val max_last_number=Int.MaxValue % 10// 最大值%10
        val min_last_number=max_last_number+1 //最小值的尾数
        for(i<- 0 until str.length()){
            //当前指示空格模式的判断
                if (space) {
                    if (str(i) == ' ') {
                        //continue ，下一步接着判断空格
                    } else if (str(i) == '+' || str(i) == '-') {
                        //说明即将进入判断数字模式。
                        //1.设置当前模式
                        space = false
                        number = true
                        //                        2.设置符号
                        sign = str(i)
                    } else if (str(i) >= '0' && str(i) <= '9') {
                        //依然是进入判断数字模式。但是符号为正，并且当前数字不为空。
                        space = false
                        number = true
                        sign = '+' //这一步可以省略，和默认值一样。
                        ans = str(i) - '0'
                    } else {
                        // 错误的字符
                        return default
                    }
                }else if(number){
                    if(str(i) >= '0' && str(i) <='9'){
                        //说明是符合条件的数字，下面判断是否会越界
                        var last_index=str(i)-'0'
                        if(sign=='+'){
                            if(ans>max_number || ans==max_number && last_index>max_last_number){
                                return Int.MaxValue
                            }else{
                                ans=ans*10+last_index
                            }
                        }else{
                            if(ans>max_number || ans==max_number && last_index>min_last_number){
                                return Int.MinValue
                            }else{
                                ans=ans*10+last_index
                            }
                        }
                        has_num=true
                    }else{
                        if(sign=='-'){
                            ans= -1 * ans
                        }
                        return ans
                    }
                }
            }
        //现在以及遍历完所有的字符了
        //只需要判断一些特例即可，has_number表示有数字
        if(has_num){
            if(sign=='-'){
                ans=ans* -1
            }
             return ans
        }else{
            return default
        }
    }

    def main(args: Array[String]): Unit = {
        val number="-91283472332"
        val ans=myAtoi(number)
        print(ans)
    }
}
```
