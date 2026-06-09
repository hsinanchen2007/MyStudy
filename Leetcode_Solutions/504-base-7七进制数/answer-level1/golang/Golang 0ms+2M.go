import (
    "fmt"
    "strconv"
)
func convertToBase7(num int) string {

	negative := false
	if num < 0 {
		negative = true
		num *= -1
	}

	res := []int{}
	for {
		if num < 7 {
			res = append(res, num)
			break
		} else {
			res = append(res, num%7)
		}
		num = num / 7
	}
	n := len(res)
    s := []string{}
	for i := n - 1; i >= 0; i-- {
        s = append(s, strconv.FormatInt(int64(res[i]), 10))
	}
    fmt.Println(s)
	if negative {
		return fmt.Sprintf("-%s", strings.Join(s, ""))
	}
	return strings.Join(s, "")
}
