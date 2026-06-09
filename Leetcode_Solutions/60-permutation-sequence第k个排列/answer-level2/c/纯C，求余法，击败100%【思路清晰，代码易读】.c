### 解题思路
方法一：求余法
1,第一个位置放置 x = k / (n - 1)!
2,第二个位置放置 x = (k % (n - 1)!) / (n - 2)!
由此规律可以直接定位每个位置放置的数字

### 代码

```c

//方法一：求余法
//1,第一个位置放置 x = k / (n - 1)!
//2,第二个位置放置 x = (k % (n - 1)!) / (n - 2)!
//由此规律可以直接定位每个位置放置的数字

//函数一：计算 (n!)
int getFactorial(int n){
    int     i       = 0;
    int     iTmp    = 1;

    for (i = 1; i <= n; i++)
    {
        iTmp *= i;
    }
    return iTmp;
}

char * getPermutation(int n, int k){
    int     i       = 0;
    int     iNfac   = 0;
    char*   pRet    = NULL;
    int     iTmpA   = 0;
    int     iTmpB   = k - 1;
    char    iTmp    = 0;

    //1,初始化
    pRet = (char*)malloc(sizeof(char) * (n + 1));
    for (i = 0; i < n; i++)
    {
        pRet[i] = i + 1 + '0';
    }
    pRet[i] = '\0';

    //2,循环修改返回队列中的数值
    for (i = 0; i < n - 1; i++)
    {
        iNfac = getFactorial(n - 1 - i);    //(n-1-i)! == 当前位置一共有多少种排列
        iTmpA = iTmpB / iNfac;              //当前位置应该选择第几个数
        iTmpB = iTmpB % iNfac;              //后面还剩下几步

        //第i的位置应该填 i + iTmpA 位置上的数,可以多写几个例子，不好描述
        iTmp = pRet[i + iTmpA];
        memmove(&pRet[i + 1], &pRet[i], sizeof(char) * (iTmpA));
        pRet[i] = iTmp;
        
        //当 0==iTmpB 找到了最终的位置，跳出循环
        if (0 == iTmpB)
        {
            break;
        }
    }

    return pRet;
}
```