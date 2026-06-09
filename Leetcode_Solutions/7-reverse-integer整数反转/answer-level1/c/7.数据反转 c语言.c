### 解题思路
此处撰写解题思路
首先划定边界,明确什么时候输出数字0;其次对数据反转;最后判断是否溢出并输出结果.
### 代码

```c
int reverse(int x)
{
    int max = 2147483647, min =-2147483648;
    long result=0;
        while(x!=0)
            {
                result=result*10+x%10;
                x=x/10;
            }
    return result>max||result<min?0:result; 
}

```