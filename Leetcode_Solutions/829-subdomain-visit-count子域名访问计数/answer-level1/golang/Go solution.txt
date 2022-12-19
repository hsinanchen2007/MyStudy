### 解题思路
simple case 

### 代码

```golang
import (
	"strings"
	"strconv"
	"fmt"
)

func getSubDomains(wholeDomain string) []string {
	sps := strings.Split(wholeDomain, ".")
	subDomains := make([]string, 0,10)
	for i := 0; i < len(sps); i++ {
		subDomains = append(subDomains, strings.Join(sps[i:], "."))
	}
	return subDomains
}

func subdomainVisits(cpdomains []string) []string {
	cntMap := make(map[string]int)
    for _, val := range cpdomains {
		sps := strings.Fields(val)
		cnt, _ := strconv.Atoi(sps[0])
		subDomains := getSubDomains(sps[1])
		for _, domain := range subDomains {
			if _, ok := cntMap[domain]; ok {
				cntMap[domain] += cnt
			} else {
				cntMap[domain] = cnt
			}
		}
	}
	result := make([]string, 0, 100)
    for k, v := range cntMap {
		result = append(result, strconv.Itoa(v) + " " + k)
	}
	return result
}
```