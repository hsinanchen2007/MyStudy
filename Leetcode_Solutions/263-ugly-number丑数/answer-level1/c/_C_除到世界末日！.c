### 解题思路
使用递归的方式进行问题处理：
如一个数33，
（1）首先判断它是否可被2、3、5整除，任何一个整除都可以，如33%3=0；
（2）接着使用33/3=11继续判断，11是否可以被2、3、5整除，重复（1）步骤；如11无法整除，则不是丑数；
（3）如12可以被2/3整除，最后12/2/2=3, 3/3=1，我们num=1为终止条件，则此数为丑数；
代码如下：
![123.PNG](https://pic.leetcode-cn.com/dbb5cb2bf15befd175cbcf5701f09a45aa13857f9302bcbc2dde1ce15ddd1042-123.PNG)



### 代码

```c
int UglyNum(int num)
{
    if (num == 1) {
        return 1;
    }
    if (num % 2 != 0 && num % 3 != 0 && num % 5 != 0) {
        return 0;
    }
    int ret = 0;
    if (num % 2 == 0) {
        ret = UglyNum(num / 2);
    } else if (num % 3 == 0) {
        ret = UglyNum(num / 3);
    } else if (num % 5 == 0) {
        ret = UglyNum(num / 5);
    }
    return ret;
}
bool isUgly(int num) {
    if (num <= 0) {
        return false;
    }
    int ret;
    ret = UglyNum(num);
    return ret > 0 ? true : false;
}
```