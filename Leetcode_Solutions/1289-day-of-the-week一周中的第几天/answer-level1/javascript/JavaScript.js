```
var dayOfTheWeek = function(day, month, year) {
    let obj = {
        0: 'Sunday',
        1: 'Monday',
        2: 'Tuesday',
        3: 'Wednesday',
        4: 'Thursday',
        5: 'Friday',
        6: 'Saturday'
    }
    let date = new Date();
    date.setYear(year);
    date.setMonth(month - 1);
    date.setDate(day);
    return obj[date.getDay()]
};
```
