### 解题思路
此处撰写解题思路
首先找到重复的数
减去重复的数，再加上等量的没有提到的数

### 代码

```c
int minIncrementForUnique(int* A, int ASize){
    //找到重复出现的数，列出数组
    //若为0，则下面加至其数
    int count[80000];
    int n=0;
    for(int i=0;i<80000;i++)
    {
        count[i]=0;
    }//计数
    for(int i=0;i<ASize;i++)
    {
        count[A[i]]+=1;
    }//计数
    for(int i=0;i<80000;i++)
    {
        if(count[i]>=2)
        {
            n=n-(count[i]-1)*i;//要减去几个数字的和
        }
    }
    for(int i=0;i<80000;i++)
    {
        if(count[i]>1)//定位多余的数字
        {
            
            for(int j=i+1;j<80000;j++)
            {
                
                if(count[j]==0)
                {
                    count[j]=1;
                    count[i]--;
                    n+=j;
                    
                }
                if(count[i]==1)
                {
                    break;
                }
            }
            
        }
        
    }
    return n;
}
```