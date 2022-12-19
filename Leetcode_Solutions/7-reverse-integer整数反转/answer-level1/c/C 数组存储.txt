### 解题思路
每次都对原数按10的i+1次方取余，再用余数除以10的i次方。
123%10/1=3      a[0]
123%100/10=2    a[1]
123%1000/100=1  a[2]
123%10000/1000=0
### 代码

```c
double ppow(int n);
int reverse(int x){
    long result=0;
    int i=0;
    int *array;
    array=(int *)malloc(32*sizeof(int));//
    //int array[32];
    while(1&&i<32){
    //while(x!=0){
        // array[i] = x%10;
        // x = x/10;
        // i++;
        array[i]=x%((int)ppow(i+1))/(int)ppow(i);
        if(array[i]==0&&x/(int)ppow(i)==0) break;
        i++;
    }
    for(int k=0;k<i;k++){
        result=result+(long)array[k]*ppow(i-k-1);
    }
    if((int)result != result){
        return 0;
    }
    return (int)result;

}
//计算10的n次方
double ppow(int n){
    double result=1;
    if(n==0) return 1;
    for(int i=0;i<n;i++){
        result=result*10;
    }
    return result;
}
```