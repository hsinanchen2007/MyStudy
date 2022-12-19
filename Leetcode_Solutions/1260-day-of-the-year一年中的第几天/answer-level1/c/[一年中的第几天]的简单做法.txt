### 解题思路

1. 提取字符串中的 [年],[月],[日] 三个数字,利用数字字符的ASCII字符的值与实际数值相差一个'0',做差乘以[位权]
2. 判断是否为闰年, 累加月份的天数(例如3月就累加1和2月的天数month-1) + 日期数
3. 还可以优化, 将数组设置为已经累加好的月份天数, 优化执行效率

### 代码

```c
int dayOfYear(char * date){
    int year = (date[0]-'0')*1000 + (date[1]-'0')*100 + (date[2]-'0')*10 +(date[3]-'0');
    int month = (date[5]-'0')*10 + (date[6]-'0');
    int day = (date[8]-'0')*10 + (date[9]-'0');

    int arr1[]={31, 28, 31, 30, 31,30, 31, 31, 30, 31, 30,31};
    int arr2[]={31, 29, 31, 30, 31,30, 31, 31, 30, 31, 30,31};
    int res = day;
    if (year%4 == 0 && year%100!=0){
        for (int i=0; i<month-1; i++){
            res += arr2[i];
        }
    }
    else if(year%400 == 0){
        for (int i=0; i<month-1; i++){
            res += arr2[i];
        }
    }else{
        for (int i=0; i<month-1; i++){
            res += arr1[i];
        }
    }

    return res;
}
```