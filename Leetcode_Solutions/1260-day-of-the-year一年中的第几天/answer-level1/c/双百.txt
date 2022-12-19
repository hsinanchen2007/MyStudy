### 解题思路
0ms 5mb.注意平闰年以及月份数组前面插入一个0有点好用

### 代码

```c
int isRunNian(int yyyy){
    if(yyyy%400==0||(yyyy%100!=0&yyyy%4==0)){
        return 1;
    }
    return 0;
}
int dayOfYear(char * date){
    int yyyy=1000*(date[0]-'0')+100*(date[1]-'0')+10*(date[2]-'0')+(date[3]-'0');
    int mm=10*(date[5]-'0')+(date[6]-'0');
    int dd=10*(date[8]-'0')+(date[9]-'0');
    int pingnian[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int runnian[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
    //beginning with zero has some convenience
    int*year=(isRunNian(yyyy)==1)?runnian:pingnian;
    int sum=0,i=0;
    for(i=0;i<mm;i++){
        sum+=year[i];
    }
    sum+=dd;
    return sum;
}
```