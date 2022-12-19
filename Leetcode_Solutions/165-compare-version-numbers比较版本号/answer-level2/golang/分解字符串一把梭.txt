```
import (
	"strconv"
	"strings"
)

func compareVersion(version1 string, version2 string) int {
	var (
		i, j, a, b           int
		versions1, versions2 []string
		length1              int
		length2              int
	)

	versions1 = strings.Split(version1, ".")
	versions2 = strings.Split(version2, ".")
	length1 = len(versions1)
	length2 = len(versions2)

	for i < length1 && j < length2 {
		a = toInt(versions1[i])
		b = toInt(versions2[j])
		if a == b {
			i++
			j++
			continue
		}
		if a > b {
			return 1
		}
		return -1
	}
	for i < length1 {
		a = toInt(versions1[i])
		if a != 0 {
			return 1
		}
		i++
	}
	for j < length2 {
		a = toInt(versions2[j])
		if a != 0 {
			return -1
		}
		j++
	}

	return 0
}

func toInt(s string) (rtn int) {
	rtn, _ = strconv.Atoi(s)
	return
}

```
