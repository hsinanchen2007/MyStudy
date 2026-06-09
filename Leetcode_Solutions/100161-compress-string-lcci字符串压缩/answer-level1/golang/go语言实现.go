### 解题思路
1、设立标准的代码 ， 跟之前的标杆 对比

### 代码

```golang
package main

import "fmt"

func compressString(S string) string {
	if len(S) <= 1 {
		return S
	}
	var curStr = S[0]
	var res string
	var curCount = 0
	for i := 0; i < len(S); i++ {
		if curStr == S[i] {
			curCount++
		} else {
			res = res + fmt.Sprintf("%s%d", string(curStr), curCount)
			curStr = S[i]
			curCount = 1
		}
	}
	res = res + fmt.Sprintf("%s%d", string(curStr), curCount)
	if len(res) < len(S) {
		return res
	} else {
		return S
	}
}

```