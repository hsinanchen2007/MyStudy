### 解题思路

1、说明：
1）由于num1和num2的长度都小于5100，所以两个数最大的可能是各自5099个9，这时最多也是只产生一位进位，在加上末尾的'\0'，定义数组大小为5101满足条件。
2）数组acRet的定义不能用函数内的局部变量进行定义。只能定义为全局变量或者静态局部变量或者使用malloc申请内存，否则函数返回结束时，再次访问可能是NULL或者报错。
3）字符串与整数相互转换法则：cChar-'0'及cChar+'0'。
4）两数相加转为字符存入字符数组时，该数组可以不用做整体移位操作（从前向尾），可以从数组的尾部向前做存入操作（从尾向前），最后直接返回字符串首字符指针，但要保证字符串结尾有'\0'。

2、解题思路：
就是两个加数，再加上进位（0或1）的和Sum，然后进行Sum/10，Sum%10运算。


3、运行结果：
![image.png](https://pic.leetcode-cn.com/068df4c8caa05ab7ab5cd58383e89129403aa6ec601e58e00487a735979195b3-image.png)


### 代码

```c
char acRet[5101] = {'\0'};
char * addStrings(char * num1, char * num2)
{
    int iLenIdx1 = strlen(num1) - 1;
    int iLenIdx2 = strlen(num2) - 1;
    int iLen = 5099;
    int iCarry = 0;

    while((iLenIdx1>=0) || (iLenIdx2>=0) || (1==iCarry))
    {
        iCarry += (iLenIdx1>=0?num1[iLenIdx1]-'0':0) + (iLenIdx2>=0?num2[iLenIdx2]-'0':0);
        acRet[iLen] = iCarry%10 + '0';
        iCarry = iCarry/10;
        iLenIdx1--;
        iLenIdx2--;
        iLen--;
    }

    return &acRet[iLen+1];
}

/*char acRet[5101] = {'\0'};
char * addStrings(char * num1, char * num2)
{
    int iLenIndex1 = strlen(num1) - 1;
    int iLenIndex2 = strlen(num2) - 1;
    int iCarry = 0;
    int iLen = 5099;

    while((iLenIndex1>=0) || (iLenIndex2>=0) || iCarry==1)
    {
        iCarry += (iLenIndex1 >= 0 ? num1[iLenIndex1--] - '0': 0) + (iLenIndex2 >= 0 ? num2[iLenIndex2--] - '0' : 0);
        acRet[iLen--] = iCarry%10 + '0';
        iCarry /= 10;
    }
    return &acRet[iLen+1];
}*/


```