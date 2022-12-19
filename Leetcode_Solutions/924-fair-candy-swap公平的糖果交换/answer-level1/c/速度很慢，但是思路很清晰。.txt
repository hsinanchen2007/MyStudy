基本思路：爱丽丝的总和为A，鲍勃的总和为B,爱丽丝给x给鲍勃，鲍勃给y给爱丽丝，可得：
A-x+y=B-y+x，(A-B)/2=x-y
只是我觉得很纳闷，我下面写了备注，如果该地方改成break跳出循环，统一返回的话就会超过时间限制。
速度很慢，只能打败64%的C语言用户，想知道更加高效的办法。
```
int* fairCandySwap(int* A, int ASize, int* B, int BSize, int* returnSize){
    int dif,sumA,sumB,i,j;
    for(i=0;i<ASize;i++)//求出总和
        sumA=sumA+A[i];
    for(i=0;i<BSize;i++)
        sumB=sumB+B[i];

        dif=sumB-sumA;
    *returnSize=2;
    int *returnnums=(int *)malloc(sizeof(int)*(*returnSize));
    for(j=0;j<BSize;j++)
    {
            if(B[j]>dif/2)
            for(i=0;i<ASize;i++)
                if(B[j]-A[i]==dif/2)
                {
                    returnnums[0]=A[i];
                    returnnums[1]=B[j];
                    return returnnums;//用break就会超过时间
                }
    }
    return returnnums;  
}
```
