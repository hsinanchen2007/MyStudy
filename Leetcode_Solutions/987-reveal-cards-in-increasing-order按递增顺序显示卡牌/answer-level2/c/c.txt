代码如下
int* deckRevealedIncreasing(int* deck, int deckSize, int* returnSize){
    *returnSize=deckSize;
    if(deckSize == 1)
        return deck;
    int w;
    for(int i=0;i<deckSize;i++)
	{
        for(int j=0;j<deckSize;j++)
        if(deck[i]<deck[j])//进行比较
    //比较后进行交换
        {
            w=deck[i];
            deck[i]=deck[j];
            deck[j]=w;
        }
    }
    int k=2*deckSize-2;

    int a[k] ;
    for(int i=0,j=0;i<k-1;j++,i+=2){
        a[i]=deck[j];
        a[i+1]=0;
    }
    a[k-1]=deck[deckSize-1];
    for(int i=k-1,j=k-3;j>=1;j-=2,i--)
        a[j]=a[i];

    //int b[deckSize];
    int *b = (int*)malloc(sizeof(int)*(deckSize));
    for(int i=0;i<deckSize;i++)
    { b[i]=a[i];
        //printf("%d ",a[i]);
    }
   return b;
}
