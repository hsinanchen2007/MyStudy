```
func angleClock(hour int, minutes int) float64 {

	var (
		i                  int
		dig                = map[int]float64{}
		locaH, locaM, diff float64
	)
	for i = 0; i < 12; i++ {
		dig[i+1] = float64(30 * (i + 1))
	}
	dig[12] = 0

	if minutes == 0 {
		locaM = 0
	} else {
		locaM = float64(6 * minutes)
	}
	locaH = dig[hour] + float64(minutes)*30.0/60.0

	if locaH > locaM {
		diff = locaH - locaM
	} else {
		diff = locaM - locaH
	}
	if diff > 180.0 {
		diff = 360 - diff
	}
	return diff
}
```
