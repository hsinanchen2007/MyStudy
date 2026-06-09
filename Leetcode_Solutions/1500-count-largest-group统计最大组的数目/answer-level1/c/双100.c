### 解题思

### 代码

```c

int countLargestGroup(int n){
    int hush[37]={0};
    int time=1;
    int max;
    int flag;
    for(int j=1;j<=n;j++){
        flag=getit(j);
        hush[flag]++;
    }
    max=hush[1];
    for(int p=2;p<=36;p++){
        if(hush[p]>max){
            max=hush[p];
            time=1;
        }
        else if(hush[p]==max){
            time++;
        }
        else{
            ;
        }
    }
    return time;
}

int getit(int n){//9999
    int temp;
    int sum=0;
    sum+=(int)((n-n%1000)/1000);//9999-999)/1000=9
    sum+=(int)(n%1000-n%100)/100;//999-99)/100=9
    sum+=(int)(n%100-n%10)/10;//99-9)/10=9;
    sum+=(int)(n%10);//9
    return sum;

}
```