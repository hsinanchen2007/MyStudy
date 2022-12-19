### 解题思路
从头开始找.之前的字符串，去除左边的0，进行比较

### 代码

```golang
func compareVersion(version1 string, version2 string) int {
	i, j := 0, 0
	v1, v2 := 0, 0
	// 找.之前的进行比较
	for i < len(version1) || j < len(version2)  {
		for i < len(version1) {
			if version1[i] == '.' {
				i++
				break
			}
			// 过滤前面的0
			if v1 == 0 && version1[i] == '0' {
				i++
				continue
			}
			v1 = v1*10 + int(version1[i])
			i++
		}
		for j < len(version2) {
			if version2[j] == '.' {
				j++
				break
			}
			if v2 == 0 && version2[j] == '0' {
				j++
				continue
			}
			v2 = v2*10 + int(version2[j])
			j++
		}
		if v1 != v2 {
			break
		}
		// 相等就找下一对
		v1, v2 = 0, 0
	}
	if v1 > v2 {
		return 1
	} else if v1 < v2 {
		return -1
	} else {
		return 0
	}
}
```