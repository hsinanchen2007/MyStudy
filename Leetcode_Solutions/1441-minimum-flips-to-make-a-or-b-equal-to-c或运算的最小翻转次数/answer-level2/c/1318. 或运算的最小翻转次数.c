### 解题思路
给你三个正整数 a、b 和 c。

你可以对 a 和 b 的二进制表示进行位翻转操作，返回能够使按位或运算   a OR b == c  成立的最小翻转次数。

「位翻转操作」是指将一个数的二进制表示任何单个位上的 1 变成 0 或者 0 变成 1 。

 

示例 1：



输入：a = 2, b = 6, c = 5
输出：3
解释：翻转后 a = 1 , b = 4 , c = 5 使得 a OR b == c


### 代码

```c
int minFlips(int a, int b, int c){
    int aBit=0,bBit,cBit;
    int i=0,sum=0;

    for(i=0;i<32;i++){
        aBit = (a>>i) & 0x1;
        bBit = (b>>i) & 0x1;
        cBit = (c>>i) & 0x1;
        if((aBit||bBit) != cBit)
            sum += abs(aBit + bBit - cBit);
    }
    return sum;
}
```