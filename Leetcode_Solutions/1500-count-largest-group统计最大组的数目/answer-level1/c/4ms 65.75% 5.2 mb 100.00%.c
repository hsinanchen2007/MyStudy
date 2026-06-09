### 解题思路
n最大为10000，故最大各位数和不超过36
### 代码

```c
int sumByPos(int i){
    int sum=0;
    while(i>0){
        sum+=(i%10);
        i/=10;
    }
    return sum;
}
int countLargestGroup(int n){
    int a[40]={0};
    int i=1,max=0;
    while(i<=n){
        int temp=sumByPos(i);
        a[temp]++;
        if(a[temp]>max){
            max=a[temp];
        }
        i++;
    }
    i=0;
    int sum=0;
    while(i<40){
        if(a[i]==max){
            sum++;
        }
        i++;
    }
    return sum;
}
```