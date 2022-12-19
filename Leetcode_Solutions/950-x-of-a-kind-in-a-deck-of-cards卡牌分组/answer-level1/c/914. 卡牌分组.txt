### 解题思路

    其实就是求deck数组中各个数字出现次数的最大公约数，如果最大公约数不是1，那就返回true，否则就是false。
    
    再次吐槽leetcode的题目描述，根本就是再考阅读理解。



### 代码

```c
bool hasGroupsSizeX(int* deck, int deckSize)
{
    int nums[10000+1]={0},Xmax=100000,dmax=0,dmin=100000;

    for(int i=0;i<deckSize;i++)
    {   
        nums[deck[i]]++;
        if(deck[i]>dmax){dmax=deck[i];}
        if(deck[i]<dmin){dmin=deck[i];}
    }

    for(int i=0;i<10001;i++)
    {
        if(nums[i]>0&&nums[i]<Xmax)
        {
            Xmax=nums[i];
        }
    }    

    if(Xmax==1)
    {
        return false;
    }

    //printf("dmin=%d dmax=%d \n",dmin,dmax);

    for(int X=2;X<=Xmax;X++)
    {
        int i;
        for(i=dmin;i<=dmax;i++)
        {
            //printf("nums[%d]=%d ",i,nums[i]);
            if(nums[i]>1&&nums[i]%X!=0)
            {
                break;
            }
        }
        if(i>dmax)
        {
            return true;
        } 
    }

    return false;
}
```