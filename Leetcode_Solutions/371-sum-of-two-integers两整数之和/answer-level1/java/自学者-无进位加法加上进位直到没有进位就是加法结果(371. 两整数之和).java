### 解题思路
* 无进位加法加上进位直到没有进位就是加法结果
* 调整一下编码风格，更加方便理解

### 踩坑
* 如果不了解进位非进位，基本没有解决思路
* 理解其他人的题解比较费劲，修改成自己的编码风格，容易理解一些

### 代码

```java
class Solution {
    /**
     * 计算公式：oprA + oprB = sum
     */
    public int getSum(int a, int b) {
        int oprA = a;
        int oprB = b;        
        while(oprB != 0)
        {
            //在位运算操作中，异或的一个重要特性是无进位加法
            int noCarrySum = oprA ^ oprB;
            //找到进位的数，把无进位加法结果和进位相加得到最终结果
            //进位直到进位为零，计算结束
            int carry = (oprA & oprB) << 1;            
            //准备下一个加法计算
            oprA = noCarrySum;
            oprB = carry;
        }
        return oprA;
    }
}
```