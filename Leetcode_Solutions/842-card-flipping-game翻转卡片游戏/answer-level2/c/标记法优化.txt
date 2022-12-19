### 解题思路
思路没有什么特殊的，也是先找到正反面都一样的卡片，把这些数字记录到数组中，称为newArray。
再对正反面不一样的卡片的数字查询：
  1）不在newArray的数据才有效
  2）一边查询一边当前最小值，最后返回最小值即可。

方法上用了点小技巧，用标记法减少了查询次数；每个标记用char型减少了内存开销，如果你愿意还可以使用bit。

### 代码

```c
#define MAX_NUM 2000

static char newArray[MAX_NUM];

int flipgame(int* fronts, int frontsSize, int* backs, int backsSize){

	int i=0;
	int min = 0;

    if(fronts == NULL || backs == NULL || \
        frontsSize!=backsSize || frontsSize<= 0)
    {
        printf("invalid param!\n");
        return -1;
    }

    //newArray = malloc(sizeof(char) * MAX_NUM);
    memset(newArray,0,sizeof(char) * MAX_NUM);
    
    for(i=0;i<frontsSize;i++)
    {
    	if(fronts[i] == backs[i] && fronts[i]<=MAX_NUM)
    	{
    		newArray[fronts[i]-1] = 1;
    		//printf("newArray(%d):%d\n",act_int-1,newArray[act_int-1]);
    	}
	}

    min=0x1FFFFFFF;
	for(i=0;i<frontsSize;i++)
	{
		if(fronts[i] != backs[i])
		{
            if(fronts[i] < min && fronts[i]<=MAX_NUM)
            {
                if(newArray[fronts[i]-1] == 0)
                {
                    min = fronts[i];
                    //printf("tmp front min:%d\n",min);
                }
            }
			
			if(backs[i] < min && backs[i]<=MAX_NUM)
            {
                if(newArray[backs[i]-1] == 0)
                {
                    min = backs[i];
                    //printf("tmp back min:%d\n",min);
                }
            }
		}
	}
	
	//free(newArray);
	
	if(min == 0x1FFFFFFF)
	    min = 0;
	
	return min;
}
```