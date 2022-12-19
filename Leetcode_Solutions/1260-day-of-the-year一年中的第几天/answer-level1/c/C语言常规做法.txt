```c
int dayOfYear(char * date){
    int year=0,month=0,day=0,result=0,i;
    int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    for(i=0;i<4;i++) year=year*10+date[i]-48;
    for(i=5;i<7;i++) month=month*10+date[i]-48;
    for(i=8;i<10;i++) day=day*10+date[i]-48;

    if(year%4==0&&year%100!=0||year%400==0) days[1]=29;
    for(i=0;i<month-1;i++) result=result+days[i];
    result=result+day;
    return result;
}
```