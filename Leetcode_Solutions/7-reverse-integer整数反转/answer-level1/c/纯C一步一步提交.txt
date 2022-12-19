### 解题思路
通过越界考虑进行判断，先取出每个位上的数据在依次进行翻转

### 代码

```c
int reverse(int x)
{
    //考虑越界问题
    int max = 2147483647, min =-2147483648;
    int res[32] = {0};
    long reslut =0;
    int num=0;
    //取出每个位上的数据
    while(x/10 || x%10)
    {
        res[num] = (x % 10);
        x=x/10;
        num++;
    }
    //进行翻转变换
    for(int i = 0;i<num;i++)
    {
        reslut +=res[i] * pow(10 ,(num-i-1));
    }

    reslut = reslut>max||reslut<min?0:reslut;
    
    return reslut;
}
```