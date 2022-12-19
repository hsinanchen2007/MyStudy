```go
func ordinalOfDate(date string) int {
  year := string([]rune(date)[:4])
  y, _ := strconv.Atoi(year)
  days := test(y)

  for i, day := range days {
    if day == date {
      return i + 1
    }
  }
  return 0
}

func test(year int) []string {
  days := make([]string, 0)

  //year := time.Now().Year()

  for month := 1; month <= 12; month++ {
    for day := 1; day <= 31; day++ {
      //如果是2月
      if month == 2 {
        if isLeapYear(year) && day == 30 { //闰年2月29天
          break
        } else if !isLeapYear(year) && day == 29 { //平年2月28天
          break
        } else {
          days = append(days, fmt.Sprintf("%d-%02d-%02d", year, month, day))
        }
      } else if month == 4 || month == 6 || month == 9 || month == 11 { //小月踢出来
        if day == 31 {
          break
        }
        days = append(days, fmt.Sprintf("%d-%02d-%02d", year, month, day))
      } else {
        days = append(days, fmt.Sprintf("%d-%02d-%02d", year, month, day))
      }
    }
  }
  return days
}

//判断是否为闰年
func isLeapYear(year int) bool { //y == 2000, 2004
  //判断是否为闰年
  if year%4 == 0 && year%100 != 0 || year%400 == 0 {
    return true
  }

  return false
}
```

学习rockstar代码-优化

```go
func ordinalOfDate(date string) int {
    var m = []int{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    parts := strings.Split(date, "-")
    y, _:= strconv.Atoi(parts[0])
    mon, _ := strconv.Atoi(parts[1])
    d, _ := strconv.Atoi(parts[2])
    if y % 100 == 0 {
        if y % 400 == 0 {
            m[1] = 29
        }
    } else if y % 4 == 0 {
        m[1] = 29
    }
    res := d
    for i := 0; i < mon-1; i++ {
        res += m[i]
    }
    return res
}
```

继续优化，使用time标准库

```go
func ordinalOfDate(date string) int {
    t, _ := time.Parse("2006-01-02", date)
    start := time.Date(t.Year(), 1, 1, 0, 0, 0, 0, time.Local)
    return int(t.Unix() - start.Unix()) / (3600*24) + 1
}

func ordinalOfDate(date string) int {
    const format = "2006-01-02"
    t, _ := time.Parse(format, date)
    return t.YearDay()
}
```