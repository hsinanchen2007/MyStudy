### 解题思路
菜鸡打卡

### 代码

```c
int exsistsIn(int a[],int x){
    int i=0,k=7;
    for(i=0;i<k;i++){
        if(a[i]==x){
            return i;
        }
    }
    return -1;
}
int isHaoshu(int x){
    int i=0,ret=0,temp=x;
    while(x>0){
        i=x%10;
        if(i==3||i==4||i==7){
            return 0;
        }else{
            if(i==2||i==5||i==6||i==9){
                ret=1;
            }
        }
        x/=10;
    }
    return ret;
}
int rotatedDigits(int N){
    int i=1,sum=0;
    for(i=1;i<=N;i++){
        sum+=isHaoshu(i);
    }
    return sum;
}
```