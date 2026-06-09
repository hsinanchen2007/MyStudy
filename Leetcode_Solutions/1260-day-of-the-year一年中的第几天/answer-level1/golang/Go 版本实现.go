```
var monthDays = [12]int{31,28,31,30,31,30,31,31,30,31,30,31}

func dayOfYear(date string) int {
    
    year, month, day := parse(date)
    
    monthDays[1] = 28
    if isLeap(year) {
        monthDays[1] = 29
    }
    
    total := day
    for m := 0; m < month-1; m++ {
        total += monthDays[m]
    }
    
    return total
}

func parse(date string) (year, month, day int) {
    
    year, _ = strconv.Atoi(date[0:4])
    month, _ = strconv.Atoi(date[5:7])
    day, _ = strconv.Atoi(date[8:])
    
    return
}

func isLeap(year int) bool {
    // 世纪闰年
    if year % 400 == 0 {
        return true
    }
    
    // 普通闰年
    if year % 4 == 0 && year % 100 != 0 {
        return true
    }
    
    return false
}
```
