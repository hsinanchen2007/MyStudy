两个特例让我比较楞：

- .1  ---> true
- 3.  ---> true

```
import (
	"regexp"
	"strings"
)

var re = regexp.MustCompile(`(?m)^[+-]?((\d+)?\.\d+|\d+(\.)?)(e[+-]?\d+)?$`)

func isNumber(s string) bool {
	return re.MatchString(strings.TrimSpace(s))
}
```