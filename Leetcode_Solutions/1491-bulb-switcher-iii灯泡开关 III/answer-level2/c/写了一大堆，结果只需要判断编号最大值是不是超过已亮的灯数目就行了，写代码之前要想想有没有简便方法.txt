### 解题思路
方法一：O(n)看别人的题解总结来的，全部灯蓝意味着当有n个灯是亮的时候，编号1-n全都是亮的，恰好这时亮着的最大编号为n。
![numTimesAllBlue.png](https://pic.leetcode-cn.com/e696ccbb608e63ab28be16d24b11dae59280bbdb57e77ea919e6287ddd7efba7-numTimesAllBlue.png)

方法二：O(n*n)我自己的代码是暴力法，甚至超时，后来减少搜索范围才没超时。具体方法看代码，其实就是没亮一个灯就从头扫描一遍灯情况，看看是不是全蓝。
### 代码

```c
int numTimesAllBlue(int *light, int lightSize)
{
    int max=*light,count=0;
    for (int i = 0; i < lightSize; i++)
    {   
        if(*(light+i)>max)
            max=*(light+i);
        if(max==i+1)
            count++;
    }
    return count;
}
```

```c
int numTimesAllBlue(int *light, int lightSize)
{
    int count = 0;              //亮的数目
    int all_is_blue_moment = 0; //全蓝数目
    int *light_status = (int *)calloc(lightSize,sizeof(int));
    //用一个数组来表示灯亮情况 0暗1亮2蓝
    int start=0;//灯搜索的起点，不能从头搜索，会超时，全蓝之后只需要从全蓝之后的等开始搜索
    for (int i = 0; i < lightSize; i++)//一个个打开灯，判断情况
    {
        *(light_status + *(light + i) - 1) = 1;//打开的灯标位1
        
        //一个个查看灯的状态，效率很低，跳过已经全蓝的灯，从不全蓝的开始搜索才能不超时
        for (int j = start; j < lightSize; j++)
        {
            if (*(light_status + j) == 0)//遇到暗的直接退出
                break;
            else if (*(light_status + j) == 2)//遇到蓝的结束本次循环
                continue;
            else if (*(light_status + j) == 1 && j == 0)//最左边的等亮了自动变蓝，因为他没左边的灯
            {
                *(light_status + j) = 2;
                count++;
            }
            else if (*(light_status + j) == 1 && *(light_status + j - 1) == 2)//灯亮且左边是蓝的则自身也变蓝
            {
                *(light_status + j) = 2;
                count++;
            }
        }
        if (count == i + 1)//如果亮了n个灯，蓝的灯也是n，那么就是全蓝咯
        {
            all_is_blue_moment++;
            start=i;//重中之重，全蓝之后就不需要搜索这些全蓝的灯的情况了，已经知晓
            // printf("the moment is %d\n", i);
        }
    }
    // printf("%d", all_is_blue_moment);
    return all_is_blue_moment;
}
```
