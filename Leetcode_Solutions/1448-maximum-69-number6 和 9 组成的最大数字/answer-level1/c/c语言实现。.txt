### 解题思路
特殊情况特殊处理，哈哈。建立一个数组，把整数各个位的值存进去。然后从左边开始判断。左边的9越多数越大。

### 代码

```c
int maximum69Number (int num){
    //排除特殊情况
    if(num==9)
    return 9;
    if(num==99)
    return 99;
    if(num==999)
    return 999;
    if(num==9999)
    return 9999;
    int i=0,ch[4]={0};
    int temp,flag=0;
    while(num)
    {
        ch[i]=num%10;
        num/=10;
        i++;
    }
    for(int j=3;j>=0;j--)
    {
        if(ch[j]==6)
        {
            ch[j]=9;
            temp=ch[0]+ch[1]*10+ch[2]*100+ch[3]*1000;
            flag=1;break;
        }
        else
        {
            continue;
        }
    }
    if(flag==1)
    {
        return temp;
    }
    return 0;
}
```