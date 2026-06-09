- 执行用时 :4 ms, 在所有 C 提交中击败了48.00% 的用户
- 内存消耗 :6.8 MB, 在所有 C 提交中击败了100.00%的用户

```
int dayOfYear(char * date){
    int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int i;
    int year = atoi(date);
    int month = atoi(date+5)-1;
    int day = atoi(date+8);
    
    if(((year%4==0) && (year%100!=0))||(year%400==0)){ // leap year
        days[1]++;
    }
    
    for(i=0; i<month; i++){
        day += days[i];
    }
    
    return day;
}
```
