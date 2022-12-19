### 解题思路
笨办法，一天天的数，
主要几点：
    1：日期先后问题
    2：闰年问题。
此处撰写解题思路

### 代码

```c
//判断是否为闰年
int isLeapYear(int year)
{
    if ((year%4 == 0 && year%100 != 0) || (year%100 == 0 && year%400 == 0)) {
        return 1;
    } else {
        return 0;
    }
}
//将字符串自己处理返回数组日期
int * dealDate(char * date1)
{
    int *dateArr = (int *)malloc(sizeof(int)*3);
    
    //截取
    int i = 0;
    char * p;
    p = strsep(&date1, "-");
    // printf("%s %s", date1, p);
    dateArr[i] = atoi(p);
    while(date1 != NULL) {
        i++;
        p = strsep(&date1, "-");
        dateArr[i] = atoi(p);
    }

    return dateArr;
}

int caluate_day(char * date1, char * date2)
{
    int num = 0;
    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int *date1Arr = (int *)malloc(sizeof(int)*3);
    date1Arr = dealDate(date1);
    // printf("%d %d %d", date1Arr[0], date1Arr[1], date1Arr[2]);
    int *date2Arr = dealDate(date2);

    // 交换顺序，先小后大。
    if (date1Arr[0]*10000+date1Arr[1]*100+date1Arr[2] > date2Arr[0]*10000+date2Arr[1]*100+date2Arr[2]) {
        int *temp = date1Arr;
        date1Arr = date2Arr;
        date2Arr = temp;

        printf("%d %d %d\n", date1Arr[0], date1Arr[1], date1Arr[2]);
        printf("%d %d %d\n", date2Arr[0], date2Arr[1], date2Arr[2]);
    }

    while(date1Arr[0]*10000+date1Arr[1]*100+date1Arr[2] < date2Arr[0]*10000+date2Arr[1]*100+date2Arr[2]) {
        //天数加1
        num++;
        //日期向前走
        date1Arr[2]++;
        if (isLeapYear(date1Arr[0])) {
            days[1] = 29;
        } else {
            days[1] = 28;
        }
        //日进位
        if (date1Arr[2] > days[date1Arr[1]-1]) {
            //日期从0开始
            date1Arr[2] = 1;
            //月份从下月开始
            date1Arr[1]++;
            //月份进位
            if (date1Arr[1] == 13) {
                date1Arr[1] = 1;
                date1Arr[0]++;
            }
        }
    }

    return num; 
}

int daysBetweenDates(char * date1, char * date2){
    return caluate_day(date1, date2);
}

```