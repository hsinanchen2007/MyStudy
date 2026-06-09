先将数组从小到大排列，后续请查看while循环内部，较易理解。
```c
int numRabbits(int* answers, int answersSize){
    if(answersSize==0) return 0;
    int i,j,tmp;
    for(i=0;i<answersSize;i++)
        for(j=i;j<answersSize;j++)
            if(answers[j]<answers[i]){
                tmp=answers[i];
                answers[i]=answers[j];
                answers[j]=tmp;
            }
    j=0;
    int amount,result=0;
    while(j<answersSize){
        i=j;
        amount=0;
        tmp=answers[i];
        for(j=i;j<answersSize;j++){
            if(answers[j]==tmp) amount++;
            else break;
        }
        if(amount%(tmp+1)!=0) result=result+(amount/(tmp+1)+1)*(tmp+1);
        else result=result+amount;
    }
    return result;
}
```