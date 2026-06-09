### 解题思路

看官方的解法，看得我一脸懵逼，桶排序这么优雅的方法为啥没有提到呢。这题主要是计算糖的种类是不是超过糖数量的一半，超过了就返回candiesSize/2就好了，如果没有就返回让的种类。

所以用桶排序是最合适的方法，统计每种糖数量的同时，计算糖的种类，最后比较下，就可以了。

官方题解写的都是些什么玩意。。。。

### 代码

```c
int distributeCandies(int* candies, int candiesSize)
{
    int ret=0,candies_count[200000+1]={0};

    for(int i=0;i<candiesSize;i++)
    {
        if(candies_count[candies[i]+100000]==0)
        {
            ret+=1;
        }
        candies_count[candies[i]+100000]+=1;
    }

    if(candiesSize/2>ret)
    {
        return ret;
    }
    
    return candiesSize/2;
}
```