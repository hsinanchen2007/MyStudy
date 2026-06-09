### 解题思路
小白解题。不懂优化……如有不足，多谢各位指教！
能放的最多的花的数量就是连续0的个数减一除以2的结果的和。
i用于循环的遍历数组，max用于算总共最多可以放花的数量，count用于算连续的0的个数。
注意开头为0以及结尾为0的情况。
而且因为是在有不是0的数字的时候再更新max和count，因此需要增加一下count是否为0的判断，以免结尾也为0但是max没更新。
（啊，好像最后一个数字是否为0的判断鸡肋了，不需要也可以的，因为如果循环结束之后count仍然不为0，结尾数字一定是0的……）
### 代码

```c
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
    int i,max=0,count=0;
    if(flowerbed[0]==0)
     count++;
    for(i=0;i<flowerbedSize;i++)
    {
        if(flowerbed[i]==0)
         count++;
        else
        {
            max+=(count-1)/2;
            count=0;
        }
    }
    if(count!=0)
    {
        if(flowerbed[flowerbedSize-1]==0)
         count++;
        max+=(count-1)/2;
    }
    return max>=n;
}
```