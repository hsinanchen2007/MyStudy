### 解题思路
这个解题思路是我看到的最好的解题思路了.
原作者实在是太让我佩服了,我希望我有朝一日也能够独立写出这样的代码.
### 代码

```c
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n)
{
    short gap=1,i;
    // 从第一个元素开始看
    for(i=0;i<flowerbedSize;i++)
    {   
        // 如果flowerbed[i]==0,说明两个1之间的距离又增加了1;
        if(flowerbed[i]==0) gap++;
        // 如果flowerbed[i]!=0,说明出现了两个1,那么这两个1之间可以插入的花朵数为(gap-1)/2
        // 最简单的例子:三个坑可以插入1朵花,五个坑可以栽培2朵话
        else
        {
            n=n-(gap-1)/2;
            // 这时候gap需要重新计算,即当前面的元素不是1的时候,gap增加,如果前面出现的是1,那么gap不需要增加.
            gap=0;
        }
    }
    // 数到数组的最末尾的时候,如果仍旧有gap那么就可以栽gap/2的花朵
    if(gap!=0) n=n-gap/2;
    return n<=0;
}
// 总结 多学学人家的思路,看看人家写的多好!
```