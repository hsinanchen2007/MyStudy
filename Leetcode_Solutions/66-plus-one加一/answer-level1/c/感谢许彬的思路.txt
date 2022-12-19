### 解题思路
先写这道题的解题思路，然后在总结的时候再写之前的错误思路。
以测试用例[1,2,3]演示
i指向最后一位的位置
最后一位是[3]只要digit[i]+1即可。
测试用例[9]演示
最后一位是9，说明要进位，且溢出变成位数10
所以需要重新建立一个数组返回。
测试用例[1,9]演示
最后一位9，进位，不溢出，i继续移动到十位上，1+1=2 不溢出，返回[2,0]即可。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int i = digitsSize - 1;//从0开始计数
    for(i;i>=0;i--){
        if(digits[i]<9){//如果小于9直接加1
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }
        digits[i]=0;//否则这一位置为0，然后判断下一位，下一位加1
    }
    //如果进行到这一步说明为全9 如：99，999，9999等
    //需要多分配一位来容纳 如：99+1=100 变成三位数
    // aaa = malloced(sizeof(int * digitsSize + 1));写的什么狗屁分配函数
    int* result = (int*) malloc ((digitsSize+1) * sizeof(int));//一定要有括号括起来！！
    result[0]=1;//第一位是1，其余位为0.参看100即可
    for(i=1;i<=digitsSize;++i) result[i]=0;
    *returnSize = digitsSize + 1;
    return result;
}
```
### 总结
1、分配空间函数写了很多次，依旧记不住，需要着重学习这里的写法。
2、最开始思路是提取数组里面的数据，转换为数字型，然后在利用/和%运算变换成一个数组存储进去。这样的思路是在是过于麻烦。
3、这道题给了我一个新的解题思路。

Ice Bear。