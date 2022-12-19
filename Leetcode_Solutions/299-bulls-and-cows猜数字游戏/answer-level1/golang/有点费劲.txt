![image.png](https://pic.leetcode-cn.com/78678b18ce5cb76a87cd9cc1d9bfaa671b224d6c999625b5cfc05466d18b14d6-image.png)

```
func getHint(secret string, guess string) string {
	var countA int = 0
	var countB int = 0
	var arr1 = make([]int, 10)
	var arr2 = make([]int, 10)
	
	for i := 0; i < len(secret); i++ {
		t1, _ := strconv.Atoi(string(secret[i]))
		arr1[t1] = arr1[t1] + 1
		t2, _ := strconv.Atoi(string(guess[i]))
		arr2[t2] = arr2[t2] + 1
		if secret[i] == guess[i] {
			countA++
			t1, _ := strconv.Atoi(string(secret[i]))
			arr1[t1]--
			arr2[t1]--
		}
	}

	// fmt.Println(arr1)
	// fmt.Println(arr2)
	
	for i := 0; i < len(arr1); i++ {
		if arr2[i] <= arr1[i] && arr1[i] != 0 {
			countB += arr2[i]
		} else if arr2[i] > arr1[i] {
			countB += arr1[i]
		}
	}
	
	// fmt.Println(countA)
	// fmt.Println(countB)
	return fmt.Sprintf("%dA%dB", nb, nc)
}
```
