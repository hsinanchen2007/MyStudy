### 解题思路
非常常规可能还有点死板的算法吧。如果一个正整数（不包括1）不断除以2直到商为1且在此过程中余数始终为0，则这个数是2的幂。先对0、1和奇数单独讨论。
然后就是大于等于2的偶数。与运算有个性质：一真一假结果为假，全真为真。while条件一定满足，退出条件违背其中一个。如果过程中余数不为0，一定不是2的幂；如果一直到商为1，是2的幂。
侥幸：
![aaa.jpg](https://pic.leetcode-cn.com/34f3e1bfd6763df088c5530c4a971eceb2412a017b75c6551fc632b20d51a9ef-aaa.jpg)

代码如下：

### 代码

```c
bool isPowerOfTwo(int n){
    bool result=true;
    int x=n;
    int y=0;

    if(n==0){
        return false;
    }
    if(n == 1){
        return true;
    }
    if(n % 2 != 0){
        return false;
    }
    while(x!=1 && y==0){
        x=x/2;
        y=x%2;
    }
    if(y!=0){
        result=false;
    }
    if(x==1){
        result=true;
    }
    return result;
}
```