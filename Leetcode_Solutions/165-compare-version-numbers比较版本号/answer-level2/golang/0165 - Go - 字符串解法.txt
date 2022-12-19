首先当前题目中测试用例肯定是不完善的
![image.png](https://pic.leetcode-cn.com/76667a0667ab7b0adf4e6e950cd309c82505571b7ac15f98bfb23da780208b88-image.png)
根据题目来看，理应输出-1，而期望却是0。

---

根据题目来看，并未限制版本号的大小，所以如果使用字符串转数字的解法，当版本号超级大的时候，一定会出问题。

所以应该使用大字符串比较的方法。（而且题目标签也是`字符串`）

1. 对两个版本号进行切割，得到两份版本数组。
2. 补全两份版本数组到一样的长度，短的后面补0。
3. 比较版本数组中每一个版本的大小。

比较两个字符串数字的方法有很多，我这里使用了将两个字符长度补齐的方法，在短的字符串前面补充上足够的0，然后逐位进行比较。

```go
func compareVersion(version1 string, version2 string) int {
	v1 := strings.Split(version1, ".")
	v2 := strings.Split(version2, ".")

	for len(v1) < len(v2) {
		v1 = append(v1, "0")
	}
	for len(v2) < len(v1) {
		v2 = append(v2, "0")
	}

	l := len(v1)
	for i := 0; i < l; i++ {
		vs1 := strings.TrimLeft(v1[i], "0")
		vs2 := strings.TrimLeft(v2[i], "0")

		for len(vs1) < len(vs2) {
			vs1 = "0" + vs1
		}
		for len(vs2) < len(vs1) {
			vs2 = "0" + vs2
		}

		vl := len(vs1)
		for j := 0; j < vl; j++ {
			if vs1[j] == vs2[j] {
				continue
			}

			if vs1[j] < vs2[j] {
				return -1
			}

			return 1
		}
	}

	return 0
}
```





