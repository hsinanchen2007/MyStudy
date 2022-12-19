### 解题思路
![微信图片_20200225211117.png](https://pic.leetcode-cn.com/3e10697f8c542a7d10065764a79ddef234111e6f4a34264b504f72605710f659-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200225211117.png)
最基本的解法，各位取余判断，是否满足条件；
最后转换为10进制数，与原数进行对比判断

### 代码

```c
bool confusingNumber(int N){

    int input = N;
    int out = 0;
    int n[11] = {0};
    int index =0;
    while(input!=0)
    {
        switch(input%10)
        {
            case 0:
            case 1:
            case 8:
            n[index] = input%10;
            break;
            case 6:
            n[index] = 9;
            break;
            case 9:
            n[index] = 6;
            break;
            default :
              return false;
        }
        index ++;
        input/=10;
    }
    for(int i=0;i<index;i++)
    {
        out=out*10+n[i];
    }
    if(N!=out)
    return true;
    else
    return false;
}
```