int* deckRevealedIncreasing(int* deck, int deckSize, int* returnSize)
{
    int i=0,j,temp,min,minsub,l;
    for(;i<deckSize-1;i++)  //采用选择法 对deck从小到大排序
    {
        min=deck[i],minsub=i;
        for(j=i+1;j<deckSize;j++)
        {
            if(deck[j]<min)
            {
                min=deck[j],minsub=j;
            }
        }
        if(minsub!=i)
        {
            temp=deck[i];
            deck[i]=deck[minsub];
            deck[minsub]=temp;
        }
    }           //下面采用步骤说明的逆步骤  将排好序的deck逆推  得到答案
    i=deckSize-2,j=deckSize-1;   // i到j的位置代表有效数字 
    for(;i>0;i--)                // i--代表  有效数字加一  即步骤1的逆步骤
    {                  
        for(l=j;l>i;l--)         //将最后一个数字提到目前有效的数字最前面  即步骤2 的逆步骤
        {
            temp=deck[l];
            deck[l]=deck[l-1];
            deck[l-1]=temp;
        }
    }           
    return(deck);  
}


看到这里辛苦你了   该算法思路没错  但代码一定有错   可我也找不出来哪里有错   所以期待网友的指正