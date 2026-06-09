##分钟化 + 排序比较

```

func timeToMinute(time string) int  {
	var times = strings.Split(time,":")
	var minute int
	 if temp,err := strconv.Atoi(times[0]);err == nil{
	 	minute = minute+ temp*60
	 }
	if temp,err := strconv.Atoi(times[1]);err == nil{
		minute = minute + temp
	}
	return minute
}




func findMinDifference(timePoints []string) int {
	var minutes = make([]int,len(timePoints))

	for index,value := range timePoints {
		minutes[index] = timeToMinute(value)
	}
	sort.Ints(minutes)
	var minMin = minutes[0]+24*60-minutes[len(minutes)-1]
	for i:=0;i<len(minutes)-1 ;i++  {
		if minutes[i+1] - minutes[i] < minMin{
			minMin =  minutes[i+1] - minutes[i]
		}
	}
	return minMin
}
```
