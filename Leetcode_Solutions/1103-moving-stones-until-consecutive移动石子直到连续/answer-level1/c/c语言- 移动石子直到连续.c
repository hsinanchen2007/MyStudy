### 解题思路
这题好烦哈哈哈哈

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numMovesStones(int a, int b, int c, int* returnSize){
        int *returnA=(int *)malloc(sizeof(int)*(2));
        * returnSize=2;
        int temp,min,max;
        if(a>b){
            temp=a;
            a=b;
            b=temp;
        }
        if(b>c){
            temp=c;
            c=b;
            b=temp;
        }
        if(a>b){
            temp=a;
            a=b;
            b=temp;
        }
        int d1=b-a,d2=c-b;
        if(d1<1||d2<1){
            min=0;
            max=0;
            
        }
       else   if(d1>2&&d2>2){
           min=2;
            max=d1+d2-2;
           

        }
        else if(d1==2||d2==2){
            min=1;
             max=d1+d2-2;
        }
       else  if(d1==1&&d2==1){
            min=0;
           max=0;
           
        }
        else if(d1==1){
           min=1;
            max=d2-1;
            
        }
        else if(d2==1){
            min=1;
            max=d1-1;
           
        }
        returnA[0]=min;
        returnA[1]=max;
       return returnA;
}
```