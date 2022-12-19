### 解题思路
这道题充分运用了异或运算的各种性质
并且学习了提交记录中排第一的优化方案

首先要知道异或运算的几个性质
- 交换律
- 结合律（即(a^b)^c == a^(b^c)）
- 对于任何数x，都有x^x=0，x^0=x
- 自反性 A XOR B XOR B = A xor  0 = A ---> A XOR B = C 则 C XOR B = A
以上摘自[异或的性质及运用](https://www.cnblogs.com/suoloveyou/archive/2012/04/25/2470292.html)

具体思路其他题解都说的很明白了，这里就直接结合代码在注释中说明几种性质的运用。
![image.png](https://pic.leetcode-cn.com/3364b1e194aa4155817ea0eea27d210992176b75cec1c0d613eaa8ce87f57994-image.png)


### 代码

```java
class Solution {
    // 假设结果数为A B
    public int[] singleNumbers(int[] nums) {
        int x = 0; // 用于记录 A B 的异或结果
        
        /** 得到A^B的结果 
            基于异或运算的以下几个性质 
                1. 交换律 
                2. 结合律 
                3. 对于任何数x，都有x^x=0，x^0=x 
        */
        for (int val : nums) x ^= val;

        // x & (-x)本身的作用是得到最低位的1，
        int flag = x & (-x); 
        // 而我们所需要的做到的是：利用这个1来进行分组，也就是做到将A和B区分开
        // 前面已经知道，x是我们需要的结果数A和B相异或的结果，也就是说，x的二进制串上的任何一个1，都能成为区分A和B的条件
        // 因此我们只需要得到x上的任意一个1，就可以做到将A和B区分开来
        

        int res = 0; // 用于记录A或B其中一者

        // 分组操作
        for (int val : nums) {
            // 根据二进制位上的那个“1”进行分组
            // 需要注意的是，分组的结果必然是相同的数在相同的组，且还有一个结果数
            // 因此每组的数再与res=0一路异或下去，最终会得到那个结果数A或B
            // 且由于异或运算具有自反性，因此只需得到其中一个数即可
            if ((flag & val) != 0) {
                res ^= val;
            }
        }
        // 利用先前的x进行异或运算得到另一个，即利用自反性
        return new int[] {res, x ^ res};
    }
}
```