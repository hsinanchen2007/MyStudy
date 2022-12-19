1:判断月份是否是1 2 月，这样不用判断闰年
2:判断闰年把2月改成29日
3:循环增加天数

```
var dayOfYear = function(date) {
    let [year,month,day] = date.split('-').map(parseFloat);
    let arr = [0,31,28,31,30,31,30,31,31,30,31,30,31];
    let res = 0;

    if(month<3){
        return arr[month-1]+day
    }
    if(year % 4 ==0 && year % 100 != 0 || year %400 == 0){
        arr[2] = 29
    }
    for(let i =1;i<month;i++){
        res += arr[i]
    }
    return res+day
};
```
