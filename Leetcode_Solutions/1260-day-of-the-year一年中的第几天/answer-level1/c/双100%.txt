![百分百.png](https://pic.leetcode-cn.com/66eed5da64bf258d7bce14eed21ee9d2d901181a35f8bfad86acb93570b6bd08-%E7%99%BE%E5%88%86%E7%99%BE.png)
```
int judgeYear(int year){
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return 29;
	return 28;
}
int judgeMonth(int year, int month, int day){
	switch(month){
		case 1:break;
        case 2:day += 31;break;
        case 3:day += (31 + judgeYear(year));break;
        case 4:day += (62 + judgeYear(year));break;
        case 5:day += (92 + judgeYear(year));break;
        case 6:day += (123 + judgeYear(year));break;
        case 7:day += (153 + judgeYear(year));break;
        case 8:day += (184 + judgeYear(year));break;
        case 9:day += (215 + judgeYear(year));break;
        case 10:day += (245 + judgeYear(year));break;
        case 11:day += (276 + judgeYear(year));break;
        case 12:day += (306 + judgeYear(year));break;
        default:break;
	}
	return day;
}
int dayOfYear(char * date){
    int year;
    int month;
    int day;

    sscanf(date, "%d-%d-%d", &year, &month, &day);
    return judgeMonth(year, month, day);
}
```

