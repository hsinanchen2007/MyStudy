### 解题思路
此处撰写解题思路
是参考leetcode 回文数算法题 题解 方法三做的 链接如下
https://leetcode-cn.com/problems/palindrome-number/solution/dong-hua-hui-wen-shu-de-san-chong-jie-fa-fa-jie-ch/

方法三介绍了怎么将一个int类型进行反转。采用不断取余乘10的方式。
这道题如果采用转字符做，会消耗用时。
int类型转换字符串在转化为字符数组 用时会很长。

而且直接用int数字进行处理有两个好处
一是不用处理负符号
二是不用处理数字末尾的0

比较要注意的是就是溢出了
java的Integer类型自带了常量类MAX_VALUE，在32位系统下取值就是3的31次方。所以这里如果Math.pow()方法求次方的话，会浪费一定的时间。
将能做的计算前置。尽量在循环内减少计算，如把最小值的范围前置计算定义了。

尽量用double进行计算，避免产生计算的时候就溢出了。double范围>int

### 代码

```java
class Solution {
    public int reverse(int x) {
        double reverseNum = 0;
        int judgeMaxNum = Integer.MAX_VALUE;
        double judgeMinNum = -Integer.MAX_VALUE+1;
        while(x != 0) {
            reverseNum = reverseNum*10 + x%10;
            x /= 10;


            // 判断溢出
            if ((reverseNum > 0 && reverseNum >= judgeMaxNum)
                    || (reverseNum <= 0 && reverseNum < judgeMinNum)) {
                return 0;
            }
        }
        return (int)reverseNum;
    }
}
```