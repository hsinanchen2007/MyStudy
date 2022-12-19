### 解题思路
偷懒的思路（不把两个数转成2进制进行比较）：将2个数分别进行按位与和按位或，得到的2个结果进行异或，异或出来的结果转化为2进制数，其中1的个数即为所求汉明距离。

### 代码

```c
int hammingDistance(int x, int y){
    int c,d,e,temp,res,count;
    count=0;
    c=x&y;
    d=x|y;
    e=c^d;
    temp=e;
    while(1)
    {
        if((temp/2)!=0)
        {
            res=temp%2;
            temp=temp/2;
            if(res==1)
            {
                count++;
            }
        }
        else
        {
            if(temp!=0)
            {
                count++;
                break;
            }
            else
            {
                break;
            }
        }
    }
    return count;
}
```