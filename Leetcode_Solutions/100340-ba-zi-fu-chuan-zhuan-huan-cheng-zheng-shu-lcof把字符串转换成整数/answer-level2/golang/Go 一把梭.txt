```
import "math"

func strToInt(str string) int {
	var (
		i               int
		rst             int32
		begin, negative bool
		length          = len(str)
	)

	for i = 0; i < length; i++ {
		switch str[i] {
		case '+':
			if begin {
				goto LABEL_RETURN
			}
			begin = true
		case '-':
			if begin {
				goto LABEL_RETURN
			}
			negative = true
			begin = true
		case ' ':
			if begin {
				goto LABEL_RETURN
			}
		default:
			if '0' <= str[i] && str[i] <= '9' {
				var old = rst
				rst = rst*int32(10) + int32(str[i]-'0')
				if !begin {
					begin = true
				}
				if rst/10 != old {
					if negative {
						return math.MinInt32
					} else {
						return math.MaxInt32
					}
				}
			} else {
				if begin {
					goto LABEL_RETURN
				} else {
					return 0
				}
			}
		}
	}
LABEL_RETURN:
	if negative && rst > 0 {
		return -int(rst)
	}
	return int(rst)
}
```
